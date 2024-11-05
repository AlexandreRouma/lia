cmake_minimum_required(VERSION 3.13)
project(demo)

# Get all files in the source directory recursively
file(GLOB_RECURSE SRC "demo/*.cpp" "lia/*.cpp")
file(GLOB_RECURSE TEST_SRC "tests/*.cpp" "lia/*.cpp")

# Create an executable using those source file
add_executable(${PROJECT_NAME} ${SRC})
add_executable(tests ${TEST_SRC})

# Specify that the C++ version to use for the executable is C++17
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_compile_features(tests PRIVATE cxx_std_17)