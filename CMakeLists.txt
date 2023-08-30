# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(qupp)

# Setting C++ standard to 17
set(CMAKE_CXX_STANDARD 17)

# Adding custom CMake modules if any are present
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Set the source directory variable
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Create a static library for qupp_io
# Add source files and header files here
add_library(qupp_io STATIC "${SOURCE_DIR}/io/unix/io.cc" "${SOURCE_DIR}/io/include/qupp/io/io.h")

# Specify include directories for qupp_io when built and installed
target_include_directories(qupp_io
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/io/include>
)

# Install rules for qupp_io
install(TARGETS qupp_io EXPORT qupp_io_config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)
install(EXPORT qupp_io_config DESTINATION share/qupp_io/cmake)

# Create a static library for qupp
# Add source files and header files here
set(HEADER_FILES "${SOURCE_DIR}/prompt/include/qupp/prompt/prompt.h")
set(SOURCE_FILES "${SOURCE_DIR}/prompt/unix/prompt.cc")
add_library(qupp STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Specify include directories for qupp when built and installed
target_include_directories(qupp
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/prompt/include>
)

# Link qupp to qupp_io
target_link_libraries(qupp PUBLIC qupp_io)

# Install rules for qupp
install(TARGETS qupp EXPORT qupp_config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)
install(EXPORT qupp_config DESTINATION share/qupp/cmake)

# Adding examples subdirectory
add_subdirectory(examples)

# Adding Google Test for testing
find_package(GoogleTest REQUIRED)
enable_testing()
add_subdirectory(test)
