cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

add_executable(thread src/thread.cc)
target_link_libraries(thread pthread)