cmake_minimum_required(VERSION 3.16)
project(parking)

set(C_STANDARD 20)

add_executable(main main.c vehicule.c vehicule.h taxes.c taxes.h parking.c parking.h statistique.c statistique.h)
target_link_libraries(main PRIVATE m)