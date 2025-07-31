cmake_minimum_required(VERSION 3.10)
project(Genesis)

# -------------------- External Dependencies --------------------
set(SDL_DIR ${CMAKE_SOURCE_DIR}/External/SDL)
set(BGFX_DIR ${CMAKE_SOURCE_DIR}/External/bgfx)
set(BX_DIR ${CMAKE_SOURCE_DIR}/External/bx)
set(BIMG_DIR ${CMAKE_SOURCE_DIR}/External/bimg)

include_directories(
    ${SDL_DIR}/include
    ${BGFX_DIR}/include
    ${BX_DIR}/include
    ${BIMG_DIR}/include
)

# -------------------- Engine --------------------
file(GLOB_RECURSE ENGINE_SRC "Engine/src/*.cpp")
file(GLOB_RECURSE ENGINE_HEADERS "Engine/include/*.h")

add_library(Engine ${ENGINE_SRC} ${ENGINE_HEADERS})
target_include_directories(Engine PUBLIC Engine/include)

# -------------------- Game --------------------
file(GLOB_RECURSE GAME_SRC "Game/src/*.cpp")
file(GLOB_RECURSE GAME_HEADERS "Game/include/*.h")

add_library(Game ${GAME_SRC} ${GAME_HEADERS})
target_include_directories(Game PUBLIC Game/include)
target_link_libraries(Game PUBLIC Engine)

# -------------------- Shader Compiler --------------------
set(SHADERC_EXECUTABLE "${CMAKE_SOURCE_DIR}/External/bgfx/.build/win64_vs2022/bin/shadercDebug.exe")
set(SHADER_SOURCE_DIR "${CMAKE_SOURCE_DIR}/Assets/Shaders")
set(SHADER_BINARY_DIR "${CMAKE_BINARY_DIR}/Shaders")

file(MAKE_DIRECTORY ${SHADER_BINARY_DIR})

# Function to compile shaders
function(compile_shader INPUT OUTPUT TYPE)
    add_custom_command(
        OUTPUT ${OUTPUT}
        COMMAND ${SHADERC_EXECUTABLE}
            -f ${INPUT}
            -o ${OUTPUT}
            --type ${TYPE}
            --platform windows
            --profile s_5_0
            -i ${SHADER_SOURCE_DIR}
        DEPENDS ${INPUT}
        COMMENT "Compiling ${TYPE} shader: ${INPUT}"
        VERBATIM
    )
endfunction()

# Shader inputs and outputs
set(VERT_SHADER_SRC ${SHADER_SOURCE_DIR}/vs_triangle.sc)
set(FRAG_SHADER_SRC ${SHADER_SOURCE_DIR}/fs_triangle.sc)

set(VERT_SHADER_BIN ${SHADER_BINARY_DIR}/vs_triangle.bin)
set(FRAG_SHADER_BIN ${SHADER_BINARY_DIR}/fs_triangle.bin)

compile_shader(${VERT_SHADER_SRC} ${VERT_SHADER_BIN} vertex)
compile_shader(${FRAG_SHADER_SRC} ${FRAG_SHADER_BIN} fragment)

add_custom_target(Shaders ALL DEPENDS ${VERT_SHADER_BIN} ${FRAG_SHADER_BIN})

# -------------------- Executable --------------------
file(GLOB_RECURSE EXE_SRC "Executable/src/*.cpp")
file(GLOB_RECURSE EXE_HEADERS "Executable/include/*.h")

add_executable(GenesisExecutable ${EXE_SRC} ${EXE_HEADERS} ${VERT_SHADER_BIN} ${FRAG_SHADER_BIN})
target_include_directories(GenesisExecutable PUBLIC Executable/include)
target_link_libraries(GenesisExecutable PRIVATE
    Game
    Engine
    optimized ${CMAKE_SOURCE_DIR}/build/bgfx/Release/bgfx.lib
    optimized ${CMAKE_SOURCE_DIR}/build/bimg/Release/bimg.lib
    optimized ${CMAKE_SOURCE_DIR}/build/bx/Release/bx.lib
)

add_dependencies(GenesisExecutable Shaders)
