cmake_minimum_required(VERSION 3.10)
project(sparkcan-examples VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the sparkcan package
find_package(sparkcan REQUIRED)

# Define the executables and link with the sparkcan library
add_executable(example_control src/control.cpp)
add_executable(example_status src/status.cpp)

target_link_libraries(example_control PRIVATE ${sparkcan_LIBRARIES})
target_link_libraries(example_status PRIVATE ${sparkcan_LIBRARIES})