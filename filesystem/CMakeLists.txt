cmake_minimum_required(VERSION 3.5)
# project(Filesystem)
set(CMAKE_CXX_STANDARD 17)

add_executable(listFile src/list_file.cc)
add_executable(listFile_old src/list_file_old.cc)
target_link_libraries(listFile stdc++fs)

