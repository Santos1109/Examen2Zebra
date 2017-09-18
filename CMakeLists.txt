cmake_minimum_required(VERSION 3.8)
project(Examen2Zebra_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Evaluador.cpp
        Evaluador.h
        Libro.cpp
        Libro.h
        main.cpp
        NodoBinario.cpp
        NodoBinario.h)

add_executable(Examen2Zebra_master ${SOURCE_FILES})