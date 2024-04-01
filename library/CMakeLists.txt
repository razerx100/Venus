cmake_minimum_required(VERSION 3.21)

file(GLOB_RECURSE SRC src/*.cpp includes/*.hpp)

add_library(VenusLib STATIC
    ${SRC}
)

target_include_directories(VenusLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes/)

if(MSVC)
    target_compile_options(VenusLib PRIVATE /fp:fast /MP /Ot /W4 /Gy)
endif()
