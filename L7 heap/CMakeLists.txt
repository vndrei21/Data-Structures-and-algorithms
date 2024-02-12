cmake_minimum_required(VERSION 3.25)
project(L7_Matrice_Andrei)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(L7_Matrice_Andrei
        .idea/.gitignore
        .idea/workspace.xml
        App.cpp
        Matrice.cpp
        Matrice.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
