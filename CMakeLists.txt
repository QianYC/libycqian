cmake_minimum_required(VERSION 3.12)
project(libycqian)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_INSTALL_DIR /usr/local/include/
        CACHE PATH "The directory relative to CMAKE_PREFIX_PATH where ycqian header files are installed")

include_directories(ycqian)

add_executable(thread_pool examples/thread/thread_pool.cpp)
target_link_libraries(thread_pool
        pthread)

add_executable(semaphore examples/thread/semaphore.cpp)
target_link_libraries(semaphore
        pthread)

add_executable(barrier examples/thread/barrier.cpp)
target_link_libraries(barrier
        pthread)

install(DIRECTORY thread DESTINATION ${INCLUDE_INSTALL_DIR})