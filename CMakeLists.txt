cmake_minimum_required(VERSION 3.21)

project(Venus
    LANGUAGES CXX
)

set(PROJECTDIR "${CMAKE_CURRENT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(PROJECT_IS_TOP_LEVEL)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
else()
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")
endif()

file(GLOB_RECURSE SRC src/*.cpp includes/*.hpp exports/*.hpp)

if(PLATFORM STREQUAL "WINDOWS")
    file(GLOB_RECURSE SRCOPT Win32/*.hpp Win32/*.cpp)
endif()

add_library(${PROJECT_NAME} SHARED
    ${SRC} ${SRCOPT}
)

target_include_directories(${PROJECT_NAME} PRIVATE includes/ exports/)

target_compile_definitions(${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:_DEBUG>" "$<$<CONFIG:RELEASE>:NDEBUG>" BUILD_VENUS)

if(PLATFORM STREQUAL "WINDOWS")
    target_include_directories(${PROJECT_NAME} PRIVATE Win32/includes/)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VENUS_WIN32)
endif()

if(MSVC)
    string(REPLACE "/W3 " "/W4 " CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    string(REPLACE "/W3 " "/W4 " CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
    string(REPLACE "/W3 " "/W4 " CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /fp:fast /MP /EHa /Ot)
endif()

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
