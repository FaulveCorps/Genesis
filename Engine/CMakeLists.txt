file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS
    "src/*.cpp"
    "include/*.h"
)
add_library(Engine STATIC ${ENGINE_SRC})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Engine PUBLIC SDL3::SDL3)