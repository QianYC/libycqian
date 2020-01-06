cmake_minimum_required(VERSION 3.12)
project(libycqian)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

#add_library(libycqian SHARED include/barrier.hpp)
add_executable(thread_pool examples/thread_pool.cpp)
target_link_libraries(thread_pool
        pthread)

add_executable(semaphore examples/semaphore.cpp)
target_link_libraries(semaphore
        pthread)

add_executable(barrier examples/barrier.cpp)
target_link_libraries(barrier
        pthread)

