cmake_minimum_required(VERSION 3.26)
project(SerpientesEscaleras)

set(CMAKE_CXX_STANDARD 17)

add_executable(SerpientesEscaleras main.cpp
        expressGame.h
        traditionalRules.h
        dice.h
        player.h
        tablero.h
        tablero.cpp
        player.cpp
        dice.cpp
)
