cmake_minimum_required(VERSION 3.10)
project(cpv) 

# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
add_library(RingBuffer ringbuffer/ringbuffer.cc ringbuffer/ringbuffer.h)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests simple_tests.cpp)
add_executable(main main.cc ringbuffer/ringbuffer.cc)

target_link_libraries(runTests ${GTEST_LIBRARIES} RingBuffer)
