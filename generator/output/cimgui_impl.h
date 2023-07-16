#ifdef CIMGUI_USE_GLFW

typedef struct GLFWwindow GLFWwindow;
typedef struct GLFWmonitor GLFWmonitor;
struct GLFWwindow;
struct GLFWmonitor;CIMGUI_API bool ImGui_ImplGlfw_InitForOpenGL(GLFWwindow* window,bool install_callbacks);
CIMGUI_API bool ImGui_ImplGlfw_InitForVulkan(GLFWwindow* window,bool install_callbacks);
CIMGUI_API bool ImGui_ImplGlfw_InitForOther(GLFWwindow* window,bool install_callbacks);
CIMGUI_API void ImGui_ImplGlfw_Shutdown(void);
CIMGUI_API void ImGui_ImplGlfw_NewFrame(void);
CIMGUI_API void ImGui_ImplGlfw_InstallCallbacks(GLFWwindow* window);
CIMGUI_API void ImGui_ImplGlfw_RestoreCallbacks(GLFWwindow* window);
CIMGUI_API void ImGui_ImplGlfw_SetCallbacksChainForAllWindows(bool chain_for_all_windows);
CIMGUI_API void ImGui_ImplGlfw_WindowFocusCallback(GLFWwindow* window,int focused);
CIMGUI_API void ImGui_ImplGlfw_CursorEnterCallback(GLFWwindow* window,int entered);
CIMGUI_API void ImGui_ImplGlfw_CursorPosCallback(GLFWwindow* window,double x,double y);
CIMGUI_API void ImGui_ImplGlfw_MouseButtonCallback(GLFWwindow* window,int button,int action,int mods);
CIMGUI_API void ImGui_ImplGlfw_ScrollCallback(GLFWwindow* window,double xoffset,double yoffset);
CIMGUI_API void ImGui_ImplGlfw_KeyCallback(GLFWwindow* window,int key,int scancode,int action,int mods);
CIMGUI_API void ImGui_ImplGlfw_CharCallback(GLFWwindow* window,unsigned int c);
CIMGUI_API void ImGui_ImplGlfw_MonitorCallback(GLFWmonitor* monitor,int event);

#endif
#ifdef CIMGUI_USE_OPENGL3
CIMGUI_API bool ImGui_ImplOpenGL3_Init(const char* glsl_version);
CIMGUI_API void ImGui_ImplOpenGL3_Shutdown(void);
CIMGUI_API void ImGui_ImplOpenGL3_NewFrame(void);
CIMGUI_API void ImGui_ImplOpenGL3_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplOpenGL3_CreateFontsTexture(void);
CIMGUI_API void ImGui_ImplOpenGL3_DestroyFontsTexture(void);
CIMGUI_API bool ImGui_ImplOpenGL3_CreateDeviceObjects(void);
CIMGUI_API void ImGui_ImplOpenGL3_DestroyDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_OPENGL2
CIMGUI_API bool ImGui_ImplOpenGL2_Init(void);
CIMGUI_API void ImGui_ImplOpenGL2_Shutdown(void);
CIMGUI_API void ImGui_ImplOpenGL2_NewFrame(void);
CIMGUI_API void ImGui_ImplOpenGL2_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplOpenGL2_CreateFontsTexture(void);
CIMGUI_API void ImGui_ImplOpenGL2_DestroyFontsTexture(void);
CIMGUI_API bool ImGui_ImplOpenGL2_CreateDeviceObjects(void);
CIMGUI_API void ImGui_ImplOpenGL2_DestroyDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_SDL2

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
struct SDL_Window;
struct SDL_Renderer;
typedef union SDL_Event SDL_Event;CIMGUI_API bool ImGui_ImplSDL2_InitForOpenGL(SDL_Window* window,void* sdl_gl_context);
CIMGUI_API bool ImGui_ImplSDL2_InitForVulkan(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL2_InitForD3D(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL2_InitForMetal(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL2_InitForSDLRenderer(SDL_Window* window,SDL_Renderer* renderer);
CIMGUI_API void ImGui_ImplSDL2_Shutdown(void);
CIMGUI_API void ImGui_ImplSDL2_NewFrame(void);
CIMGUI_API bool ImGui_ImplSDL2_ProcessEvent(const SDL_Event* event);

#endif
#ifdef CIMGUI_USE_ALLEGRO5

typedef struct ALLEGRO_DISPLAY ALLEGRO_DISPLAY;
struct ALLEGRO_DISPLAY;
union ALLEGRO_EVENT;CIMGUI_API bool ImGui_ImplAllegro5_Init(ALLEGRO_DISPLAY* display);
CIMGUI_API void ImGui_ImplAllegro5_Shutdown(void);
CIMGUI_API void ImGui_ImplAllegro5_NewFrame(void);
CIMGUI_API void ImGui_ImplAllegro5_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplAllegro5_ProcessEvent(ALLEGRO_EVENT* event);
CIMGUI_API bool ImGui_ImplAllegro5_CreateDeviceObjects(void);
CIMGUI_API void ImGui_ImplAllegro5_InvalidateDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_ANDROID

typedef struct ANativeWindow ANativeWindow;
typedef struct AInputEvent AInputEvent;
struct ANativeWindow;
struct AInputEvent;CIMGUI_API bool ImGui_ImplAndroid_Init(ANativeWindow* window);
CIMGUI_API int32_t ImGui_ImplAndroid_HandleInputEvent(AInputEvent* input_event);
CIMGUI_API void ImGui_ImplAndroid_Shutdown(void);
CIMGUI_API void ImGui_ImplAndroid_NewFrame(void);

#endif
#ifdef CIMGUI_USE_DX9

typedef struct IDirect3DDevice9 IDirect3DDevice9;
struct IDirect3DDevice9;CIMGUI_API bool ImGui_ImplDX9_Init(IDirect3DDevice9* device);
CIMGUI_API void ImGui_ImplDX9_Shutdown(void);
CIMGUI_API void ImGui_ImplDX9_NewFrame(void);
CIMGUI_API void ImGui_ImplDX9_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplDX9_CreateDeviceObjects(void);
CIMGUI_API void ImGui_ImplDX9_InvalidateDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_DX10

typedef struct ID3D10Device ID3D10Device;
struct ID3D10Device;CIMGUI_API bool ImGui_ImplDX10_Init(ID3D10Device* device);
CIMGUI_API void ImGui_ImplDX10_Shutdown(void);
CIMGUI_API void ImGui_ImplDX10_NewFrame(void);
CIMGUI_API void ImGui_ImplDX10_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API void ImGui_ImplDX10_InvalidateDeviceObjects(void);
CIMGUI_API bool ImGui_ImplDX10_CreateDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_DX11

typedef struct ID3D11Device ID3D11Device;
typedef struct ID3D11DeviceContext ID3D11DeviceContext;
struct ID3D11Device;
struct ID3D11DeviceContext;CIMGUI_API bool ImGui_ImplDX11_Init(ID3D11Device* device,ID3D11DeviceContext* device_context);
CIMGUI_API void ImGui_ImplDX11_Shutdown(void);
CIMGUI_API void ImGui_ImplDX11_NewFrame(void);
CIMGUI_API void ImGui_ImplDX11_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API void ImGui_ImplDX11_InvalidateDeviceObjects(void);
CIMGUI_API bool ImGui_ImplDX11_CreateDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_DX12

#endif
#ifdef CIMGUI_USE_GLUT
CIMGUI_API bool ImGui_ImplGLUT_Init(void);
CIMGUI_API void ImGui_ImplGLUT_InstallFuncs(void);
CIMGUI_API void ImGui_ImplGLUT_Shutdown(void);
CIMGUI_API void ImGui_ImplGLUT_NewFrame(void);
CIMGUI_API void ImGui_ImplGLUT_ReshapeFunc(int w,int h);
CIMGUI_API void ImGui_ImplGLUT_MotionFunc(int x,int y);
CIMGUI_API void ImGui_ImplGLUT_MouseFunc(int button,int state,int x,int y);
CIMGUI_API void ImGui_ImplGLUT_MouseWheelFunc(int button,int dir,int x,int y);
CIMGUI_API void ImGui_ImplGLUT_KeyboardFunc(unsigned char c,int x,int y);
CIMGUI_API void ImGui_ImplGLUT_KeyboardUpFunc(unsigned char c,int x,int y);
CIMGUI_API void ImGui_ImplGLUT_SpecialFunc(int key,int x,int y);
CIMGUI_API void ImGui_ImplGLUT_SpecialUpFunc(int key,int x,int y);

#endif
#ifdef CIMGUI_USE_METAL

#endif
#ifdef CIMGUI_USE_OSX

#endif
#ifdef CIMGUI_USE_SDL3

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
struct SDL_Window;
struct SDL_Renderer;
typedef union SDL_Event SDL_Event;CIMGUI_API bool ImGui_ImplSDL3_InitForOpenGL(SDL_Window* window,void* sdl_gl_context);
CIMGUI_API bool ImGui_ImplSDL3_InitForVulkan(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL3_InitForD3D(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL3_InitForMetal(SDL_Window* window);
CIMGUI_API bool ImGui_ImplSDL3_InitForSDLRenderer(SDL_Window* window,SDL_Renderer* renderer);
CIMGUI_API void ImGui_ImplSDL3_Shutdown(void);
CIMGUI_API void ImGui_ImplSDL3_NewFrame(void);
CIMGUI_API bool ImGui_ImplSDL3_ProcessEvent(const SDL_Event* event);

#endif
#ifdef CIMGUI_USE_SDLRENDERER2

typedef struct SDL_Renderer SDL_Renderer;
struct SDL_Renderer;CIMGUI_API bool ImGui_ImplSDLRenderer2_Init(SDL_Renderer* renderer);
CIMGUI_API void ImGui_ImplSDLRenderer2_Shutdown(void);
CIMGUI_API void ImGui_ImplSDLRenderer2_NewFrame(void);
CIMGUI_API void ImGui_ImplSDLRenderer2_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplSDLRenderer2_CreateFontsTexture(void);
CIMGUI_API void ImGui_ImplSDLRenderer2_DestroyFontsTexture(void);
CIMGUI_API bool ImGui_ImplSDLRenderer2_CreateDeviceObjects(void);
CIMGUI_API void ImGui_ImplSDLRenderer2_DestroyDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_SDLRENDERER3

typedef struct SDL_Renderer SDL_Renderer;
struct SDL_Renderer;CIMGUI_API bool ImGui_ImplSDLRenderer3_Init(SDL_Renderer* renderer);
CIMGUI_API void ImGui_ImplSDLRenderer3_Shutdown(void);
CIMGUI_API void ImGui_ImplSDLRenderer3_NewFrame(void);
CIMGUI_API void ImGui_ImplSDLRenderer3_RenderDrawData(ImDrawData* draw_data);
CIMGUI_API bool ImGui_ImplSDLRenderer3_CreateFontsTexture(void);
CIMGUI_API void ImGui_ImplSDLRenderer3_DestroyFontsTexture(void);
CIMGUI_API bool ImGui_ImplSDLRenderer3_CreateDeviceObjects(void);
CIMGUI_API void ImGui_ImplSDLRenderer3_DestroyDeviceObjects(void);

#endif
#ifdef CIMGUI_USE_VULKAN

#endif
#ifdef CIMGUI_USE_WGPU

#endif
#ifdef CIMGUI_USE_WIN32
CIMGUI_API bool ImGui_ImplWin32_Init(void* hwnd);
CIMGUI_API bool ImGui_ImplWin32_InitForOpenGL(void* hwnd);
CIMGUI_API void ImGui_ImplWin32_Shutdown(void);
CIMGUI_API void ImGui_ImplWin32_NewFrame(void);
CIMGUI_API void ImGui_ImplWin32_EnableDpiAwareness(void);
CIMGUI_API float ImGui_ImplWin32_GetDpiScaleForHwnd(void* hwnd);
CIMGUI_API float ImGui_ImplWin32_GetDpiScaleForMonitor(void* monitor);
CIMGUI_API void ImGui_ImplWin32_EnableAlphaCompositing(void* hwnd);

#endif
