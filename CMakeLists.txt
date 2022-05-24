cmake_minimum_required(VERSION 3.16)
project(parking)

set(C_STANDARD 20)

add_executable(main main.c)
target_link_libraries(main PRIVATE m)