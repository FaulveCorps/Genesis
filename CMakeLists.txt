cmake_minimum_required(VERSION 3.10)
# SDL3
add_subdirectory(External/SDL EXCLUDE_FROM_ALL)

# Bx/Bimg (bgfx dependencies)
add_subdirectory(External/bx EXCLUDE_FROM_ALL)
add_subdirectory(External/bimg EXCLUDE_FROM_ALL)

# bgfx
add_subdirectory(External/bgfx EXCLUDE_FROM_ALL)
