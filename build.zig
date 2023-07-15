const std = @import("std");

pub fn build(b: *std.Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const imgui_dep = b.dependency("imgui", .{ .target = target, .optimize = optimize });

    const cimgui = b.addStaticLibrary(std.Build.StaticLibraryOptions{
        .name = "cimgui",
        .target = target,
        .optimize = optimize,
    });
    cimgui.addCSourceFile(thisDir() ++ "/cimgui.cpp", &.{});
    cimgui.linkLibC();
    cimgui.linkLibrary(imgui_dep.artifact("imgui"));
    cimgui.addIncludePath(imgui_dep.builder.build_root.path.?);

    b.installArtifact(cimgui);
}

inline fn thisDir() []const u8 {
    return comptime std.fs.path.dirname(@src().file) orelse ".";
}
