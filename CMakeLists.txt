cmake_minimum_required(VERSION 3.13)
project(demo)

# Get all files in the source directory recursively
file(GLOB_RECURSE SRC "demo/*.cpp" "lia/*.cpp")

# Create an executable using those source file
add_executable(${PROJECT_NAME} ${SRC})

# Specify that the C++ version to use for the executable is C++17
target_compile_options(${PROJECT_NAME} PRIVATE /std:c++17)
# /O2 /Ob2

#find_package(libusb CONFIG REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${LIBUSB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBUSB_LIBRARIES})