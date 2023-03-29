cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

add_executable(parameter_pack  src/parameter_pack.cc)

add_executable(alias_template  src/alias_template.cc)

add_executable(vector_template  src/vector_template.cc)

add_executable(array_template  src/array_template.cc)

add_executable(perfect_forwarding  src/perfect_forwarding.cc)
