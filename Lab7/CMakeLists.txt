project ("Lab7")

add_library(Lab7_lib STATIC task1.c task2.c task3.c task4.c task5.c task6.c)

add_executable(Lab7_main main.c)

target_link_libraries(Lab7_main Lab7_lib)

#add_executable(Lab7_task1 task1.c)
#add_executable(Lab7_task2 task2.c)
#add_executable(Lab7_task3 task3.c)
#add_executable(Lab7_task4 task4.c)
#add_executable(Lab7_task5 task5.c)
#add_executable(Lab7_task6 task6.c)
add_executable(Lab7_task7 task7.c)