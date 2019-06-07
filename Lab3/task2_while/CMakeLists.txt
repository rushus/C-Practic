add_library(Lab3_lib2 STATIC task1.c task2.c task3.c task4.c task5.c)

add_executable(Lab3_main2 mainwhile.c)

target_link_libraries(Lab3_main2 Lab3_lib2)