cmake_minimum_required(VERSION 3.31)
project(Lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4
        ast.cpp
        ast.h
        environment.h
        main.cpp
        parser.cpp
        parser.h
        scanner.cpp
        scanner.h
        token.cpp
        token.h
        visitor.cpp
        visitor.h)
