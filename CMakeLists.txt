cmake_minimum_required(VERSION 3.0)
project(ExampleProject)

# Add GTSAM and Boost include directories
#include_directories("/usr/include/eigen3")
#include_directories("/usr/local/include/gtsam")
#include_directories("/usr/include/boost")

# Add GTSAM and Boost libraries
#link_directories("/usr/local/lib")
#link_directories("/usr/lib/x86_64-linux-gnu")

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

find_package(GTSAM REQUIRED)
include_directories(${GTSAM_INCLUDE_DIR})

# Add executable
add_executable(ExampleProject main.cpp)

# Link against GTSAM
target_link_libraries(ExampleProject gtsam)


# Custom target to copy build directory contents to /app/build
#add_custom_target(copy_build_directory ALL
#    COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_BINARY_DIR}
#        ${CMAKE_SOURCE_DIR}/build
#)
#target_include_directories(MyExecutable PUBLIC ${GTSAM_INCLUDE_DIRS}) 
#target_include_directories(MyExecutable PUBLIC ${Boost_INCLUDE_DIRS}) 

#

#-DGTSAM_USE_SYSTEM_EIGEN=ON -DGTSAM_POSE3_EXPMAP=ON -DGTSAM_ROT3_EXPMAP=ON 
