# Define test project
project(qupp_prompt_unit)

# Add test executable
add_executable(qupp_prompt_unit test_prompt.cc)

# Link the executable with the main library and gtest
target_link_libraries(qupp_prompt_unit PRIVATE qupp gtest_main)

# Include the headers
target_include_directories(qupp_prompt_unit PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/prompt/include)

# Register the test with CTest
add_test(NAME qupp_test COMMAND qupp_prompt_unit)

