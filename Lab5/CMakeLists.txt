project ("Lab5")

add_library(Lab5_lib STATIC task1.c task2.c task3.c task4.c task5.c task6.c)

add_executable(Lab5_main task7.c)

target_link_libraries(Lab5_main Lab5_lib)