add_library(Engine STATIC)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    "${CMAKE_SOURCE_DIR}/External/SDL/include"
)

file(GLOB_RECURSE ENGINE_SRC
    src/*.cpp
    include/Engine/*.h
)

target_sources(Engine PRIVATE ${ENGINE_SRC})

option(BUILD_BULLET2_DEMOS OFF)
option(BUILD_CPU_DEMOS OFF)
option(BUILD_OPENGL3_DEMOS OFF)
option(BUILD_UNIT_TESTS OFF)
option(BUILD_EXTRAS OFF)
option(BUILD_BULLET3 OFF)

target_link_libraries(Engine PRIVATE
    "${CMAKE_SOURCE_DIR}/External/SDL/build/Release/SDL3.lib"
)

target_include_directories(Engine PUBLIC
    "${CMAKE_SOURCE_DIR}/External/Bullet/src"
)

target_link_libraries(Engine
    PUBLIC
        BulletDynamics
        BulletCollision
        LinearMath
)

file(GLOB_RECURSE ENGINE_SRC
    src/*.cpp
    include/Engine/*.h
)

message(STATUS "SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")
message(STATUS "SDL2_LIBRARY: ${SDL2_LIBRARY}")
