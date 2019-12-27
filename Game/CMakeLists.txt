cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(Game main.cpp source/Game.cpp header/Game.h source/Board.cpp header/Board.h header/Score.h source/Element.cpp header/Element.h source/Position.cpp header/Position.h source/Reumu.cpp header/Reumu.h source/Diam.cpp header/Diam.h header/Teleportations.h source/Geurchar.cpp header/Geurchar.h source/Teupor.cpp header/Teupor.h source/Oueurj.cpp header/Oueurj.h header/MovingElement.h source/IStreumon.cpp header/IStreumon.h source/PStreumon.cpp header/PStreumon.h source/XStreumon.cpp header/XStreumon.h source/SStreumon.cpp header/SStreumon.h)