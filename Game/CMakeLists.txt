file(GLOB_RECURSE GAME_SRC CONFIGURE_DEPENDS
    "src/*.cpp"
    "include/*.h"
)
add_executable(Game ${GAME_SRC})
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(Game PRIVATE Engine)
