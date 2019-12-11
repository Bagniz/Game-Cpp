cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(Game main.cpp sources/Game.cpp headers/Game.h sources/Board.cpp sources/Element.cpp headers/Element.h sources/Position.cpp headers/Position.h sources/Diam.cpp headers/Diam.h sources/Teupor.cpp headers/Teupor.h sources/Reumu.cpp headers/Reumu.h sources/Geurchar.cpp headers/Geurchar.h headers/CollisionEffect.h sources/Oueurj.cpp headers/Oueurj.h sources/XStreumon.cpp headers/XStreumon.h sources/SStreumon.cpp headers/SStreumon.h sources/PStreumon.cpp headers/PStreumon.h sources/IStreumon.cpp headers/IStreumon.h headers/Teleportations.h headers/MovingElement.h sources/Board.cpp headers/Board.h)