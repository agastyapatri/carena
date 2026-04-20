cmake_minimum_required(VERSION 3.30)
project(arena VERSION 0.1 LANGUAGES C)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)
set(SOURCES
	carena.c
)
add_executable(main main.c ${SOURCES})

