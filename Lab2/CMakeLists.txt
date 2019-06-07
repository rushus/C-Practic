project ("Lab2")

add_library(Lab2_lib STATIC task1.c task2.c)

add_executable(Lab2_main main.c)

target_link_libraries(Lab2_main Lab2_lib)