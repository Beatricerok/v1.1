cmake_minimum_required(VERSION 4.0)
add_executable(test_student
    main.cpp
)

target_include_directories(test_student PRIVATE ../)
add_test(NAME student_tests COMMAND test_student)
