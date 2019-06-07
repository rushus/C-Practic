add_library(task8_lib STATIC task7_func.c)

add_executable (Lab1_task8 task7_main.c)

target_link_libraries (Lab1_task8 task8_lib)