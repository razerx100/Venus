cmake_minimum_required(VERSION 3.21)

file(GLOB_RECURSE SRC src/*.cpp includes/*.hpp exports/*.hpp)

if(ADD_TEST_VENUS)
    set(LIBRARY_TYPE STATIC)
else()
    set(LIBRARY_TYPE SHARED)
endif()

add_library(VenusLib ${LIBRARY_TYPE}
    ${SRC}
)

set(VENUS_PRIVATE_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/includes/)

set(VENUS_PRIVATE_INCLUDES ${VENUS_PRIVATE_INCLUDES} PARENT_SCOPE)

target_include_directories(VenusLib PRIVATE ${VENUS_PRIVATE_INCLUDES})

target_include_directories(VenusLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/exports/)

target_compile_definitions(VenusLib PRIVATE BUILD_VENUS)

if(MSVC)
    target_compile_options(VenusLib PRIVATE /fp:fast /MP /Ot /W4 /Gy)
endif()
