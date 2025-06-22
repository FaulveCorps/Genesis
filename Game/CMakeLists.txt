add_executable(Game
    src/main.cpp
)

target_include_directories(Game PRIVATE
    ${CMAKE_SOURCE_DIR}/Engine/include
)

target_link_libraries(Game PRIVATE Engine)
