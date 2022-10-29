cmake_minimum_required(VERSION 3.8)
project(testThread)

set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
file(GLOB SRC src/*.cpp)
add_library(srcLib ${SRC})

message("-- src: " ${SRC})
message("-- srcLib: " srcLib)

add_executable(testThread main.cpp)
target_link_libraries(testThread srcLib)



