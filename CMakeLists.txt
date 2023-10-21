cmake_minimum_required(VERSION 3.26)
project(shell-v2)

set(CMAKE_CXX_STANDARD 23)

add_executable(main.c
        main.h
        exec_cmd.c
        main.c
        get_location.c
        my_strcpy.c
        my_strcat.c
        my_strlen.c
        my_strdup.c
        my_getenv.c
        exec_cd.c
        my_strncmp.c
        my_strcmp.c
        my_setenv.c
        my_strchr.c
        my_getline.c
)
