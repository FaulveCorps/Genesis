# Include directories for the Genesis Engine
cmake_minimum_required(VERSION 3.10)

# Definitions
add_definitions(-DBGFX_CONFIG_RENDERER_OPENGL=1)  # Or Vulkan, Metal, etc.
add_definitions(-DBGFX_CONFIG_MULTITHREADED=0)

target_include_directories(GenesisEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../External/SDL/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../External/bgfx/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../External/bx/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../External/bimg/include
)

# Source files for the Genesis Engine
target_link_libraries(GenesisEngine
    SDL3-static
    bgfx
    bx
    bimg
)
