# Genesis - v3 Revision - Dead End (Abandoned)
Abandoned due to Shader Issue in Multi-Platform Compatibility

```
C:\Users\jpfau\Desktop\Genesis>Build
[Genesis Build] Initializing Git Submodules...
[Genesis Build] Generating bgfx project with Genie...
Building configurations...
Running action 'vs2022'...
Done. Generated 0/13 projects.
[Genesis Build] Building shaderc tool via Visual Studio...
'msbuild' is not recognized as an internal or external command,
operable program or batch file.
[Genesis Build] shaderc built successfully.
[Genesis Build] Creating Build Directory...
[Genesis Build] Generating Project with CMake...
-- Selecting Windows SDK version 10.0.26100.0 to target Windows 10.0.17763.
-- Configuring done (0.2s)
-- Generating done (0.1s)
-- Build files have been written to: C:/Users/jpfau/Desktop/Genesis/build
[Genesis Build] Building Project...
MSBuild version 17.14.10+8b8e13593 for .NET Framework

  Compiling fragment shader: C:/Users/jpfau/Desktop/Genesis/Assets/Shaders/fs_triangle.sc
  Shader entry point 'void main()' is not found.
  Failed to build shader.
C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Microsoft\VC\v170\Microsoft.CppCommon.targets(254,5):
error MSB8066: Custom build for 'C:\Users\jpfau\Desktop\Genesis\build\CMakeFiles\b98b8eed483c3b8ac0caa1d225e0f525\fs_t
riangle.bin.rule;C:\Users\jpfau\Desktop\Genesis\build\CMakeFiles\b98b8eed483c3b8ac0caa1d225e0f525\vs_triangle.bin.rule
;C:\Users\jpfau\Desktop\Genesis\build\CMakeFiles\61c58d2528a99c05d7dc637f15b3b962\Shaders.rule' exited with code 1. [C
:\Users\jpfau\Desktop\Genesis\build\Shaders.vcxproj]
[Error] Build failed.

C:\Users\jpfau\Desktop\Genesis>
```
