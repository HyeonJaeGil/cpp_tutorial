cmake_minimum_required(VERSION 3.5)
# project(Filesystem)
set(CMAKE_CXX_STANDARD 17)

add_executable(functor src/functor.cc)
add_executable(vector src/vector.cc)
add_executable(vector_sort src/vector_sort.cc)
add_executable(stack src/stack.cc)
add_executable(heap src/heap.cc)
add_executable(heap_example src/heap_example.cc)
add_executable(queue_example src/queue_example.cc)
add_executable(random_variable src/random_variable.cc)

add_executable(map src/map/map.cc)
add_executable(count_frequency src/map/count_frequency.cc)
add_executable(pair src/map/pair.cc)


