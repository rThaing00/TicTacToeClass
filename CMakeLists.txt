cmake_minimum_required(VERSION 3.27)
project(TicTacToeClass)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToeClass main.cpp
        Board.cpp
        Board.h
        Player.cpp
        Player.h
        Controller.cpp
        Controller.h
        TicTacToe.cpp
        TicTacToe.h
)
