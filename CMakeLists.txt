cmake_minimum_required(VERSION 3.10)
project(qupp)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

set(SOURCE_FILES "${SOURCE_DIR}/prompt/prompt.cc")
set(HEADER_FILES "${SOURCE_DIR}/prompt/include/qupp/prompt/prompt.h")

message(STATUS "Source files: ${SOURCE_FILES}")
message(STATUS "Header files: ${HEADER_FILES}")

add_library(qupp STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(qupp
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/prompt/include>
)

install(TARGETS qupp EXPORT qupp_config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(EXPORT qupp_config DESTINATION share/qupp/cmake)

add_subdirectory(examples)

find_package(GoogleTest REQUIRED)
enable_testing()
add_subdirectory(test)

