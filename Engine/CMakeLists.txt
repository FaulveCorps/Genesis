add_library(Engine STATIC)

# Include SDL2 and engine headers
target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    "C:/Users/jpfau/Desktop/Genesis/External/SDL/include"
)

# Gather sources
file(GLOB_RECURSE ENGINE_SRC
    src/*.cpp
    include/Engine/*.h
)

target_sources(Engine PRIVATE ${ENGINE_SRC})

# Link against the built SDL2.lib
target_link_libraries(Engine PRIVATE
    "C:/Users/jpfau/Desktop/Genesis/External/SDL/build/Release/SDL3.lib"
)

file(GLOB_RECURSE ENGINE_SRC
    src/*.cpp
    include/Engine/*.h
)


message(STATUS "SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")
message(STATUS "SDL2_LIBRARY: ${SDL2_LIBRARY}")
