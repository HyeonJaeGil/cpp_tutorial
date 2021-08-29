cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

add_executable(thread src/thread.cc)
target_link_libraries(thread pthread)

add_executable(condition_variable src/condition_variable.cc)
target_link_libraries(condition_variable pthread)