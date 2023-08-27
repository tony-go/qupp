# Example CMakeLists.txt for qupp example

# Specify minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Define example project
project(qupp_example)

# Add executable
add_executable(qupp_example simple_prompt.cc)

# Link the executable with the main library
target_link_libraries(qupp_example PRIVATE qupp)

# Include the headers
target_include_directories(qupp_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/prompt/include)

