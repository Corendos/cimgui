const std = @import("std");

const BackendPlatform = enum {
    allegro5,
    glfw,
    glut,
    osx,
    sdl2,
    sdl3,
    win32,

    pub inline fn default(target: std.zig.CrossTarget) BackendPlatform {
        return switch (target.getOs().tag) {
            .linux => .glfw,
            .ios, .macos, .tvos, .watchos => .osx,
            .windows => .win32,
            else => .glfw,
        };
    }
};

const BackendRenderer = enum {
    dx9,
    dx10,
    dx11,
    dx12,
    metal,
    opengl2,
    opengl3,
    sdl2,
    sdl3,
    vulkan,
    wgpu,

    pub inline fn default(target: std.zig.CrossTarget) BackendRenderer {
        return switch (target.getOs().tag) {
            .linux => .opengl3,
            .ios, .macos, .tvos, .watchos => .metal,
            // TODO(Corendos): Make use of directx12-headers if we want to have dx12 by default.
            .windows => .dx11,
            else => .opengl3,
        };
    }
};

const Backend = struct {
    platform: BackendPlatform,
    renderer: BackendRenderer,

    pub fn from(platform: BackendPlatform, renderer: BackendRenderer) !Backend {
        const b = Backend{
            .platform = platform,
            .renderer = renderer,
        };
        return if (b.check()) b else error.InvalidBackend;
    }

    pub inline fn check(self: Backend) bool {
        _ = self;
        return true;
    }

    pub fn linkDependencies(self: Backend, b: *std.Build, step: *std.Build.CompileStep) void {
        self.platform.linkDependencies(b, step);
        self.renderer.linkDependencies(b, step);
    }
};

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const backend = try Backend.from(
        b.option(BackendPlatform, "backend_platform", "Imgui backend platform") orelse BackendPlatform.default(target),
        b.option(BackendRenderer, "backend_renderer", "Imgui backend renderer") orelse BackendRenderer.default(target),
    );
    const imgui_dep = b.dependency("imgui", .{ .target = target, .optimize = optimize, .backend_platform = backend.platform, .backend_renderer = backend.renderer });

    const cimgui = b.addStaticLibrary(std.Build.StaticLibraryOptions{
        .name = "cimgui",
        .target = target,
        .optimize = optimize,
    });
    cimgui.addCSourceFile(thisDir() ++ "/cimgui.cpp", &.{});
    cimgui.linkLibrary(imgui_dep.artifact("imgui"));
    cimgui.installHeader("cimgui.h", "cimgui/cimgui.h");

    b.installArtifact(cimgui);

    const generate_step = b.step("generate", "Generate bindings artifacts");

    const run_generator = std.Build.Step.Run.create(b, "run_generator");
    run_generator.setEnvironmentVariable("IMGUI_PATH", imgui_dep.builder.build_root.path.?);
    run_generator.cwd = "generator";
    _ = run_generator.captureStdErr();
    _ = run_generator.captureStdOut();
    run_generator.addArgs(&.{"./generator.sh"});

    generate_step.dependOn(&run_generator.step);
}

inline fn thisDir() []const u8 {
    return comptime std.fs.path.dirname(@src().file) orelse ".";
}
