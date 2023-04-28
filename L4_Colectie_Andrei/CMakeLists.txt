cmake_minimum_required(VERSION 3.25)
project(Colectie)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Colectie
        .idea/.gitignore
        .idea/workspace.xml
        App.cpp
        Colectie.cpp
        Colectie.h
        IteratorColectie.cpp
        IteratorColectie.h TestScurt.h TestScurt.cpp TestExtins.h TestExtins.cpp)
