cmake_minimum_required(VERSION 3.5)
project(thread_pool)

set(CMAKE_CXX_STANDARD 11)

add_executable(thread_pool_test thread_pool_test.cc thread_pool.cc)
target_link_libraries(thread_pool_test pthread)
