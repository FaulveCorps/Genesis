cmake_minimum_required(VERSION 3.15)
project(GenesisEngine)

add_subdirectory(External/Bullet)

add_subdirectory(Engine)

add_executable(Game Game/src/main.cpp)
target_link_libraries(Game PRIVATE Engine)

if(WIN32)
    target_compile_definitions(Game PRIVATE PLATFORM_WINDOWS)
elseif(APPLE)
    target_compile_definitions(Game PRIVATE PLATFORM_MACOS)
elseif(UNIX)
    target_compile_definitions(Game PRIVATE PLATFORM_LINUX)
endif()

add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/External/SDL/build/Release/SDL3.dll"
        $<TARGET_FILE_DIR:Game>)
