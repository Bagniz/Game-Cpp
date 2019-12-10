cmake_minimum_required(VERSION 3.15)
project(Game)

set(CMAKE_CXX_STANDARD 11)

add_executable(Game main.cpp Game.cpp Game.h Board.cpp Board.h Element.cpp Element.h Position.cpp Position.h Diam.cpp Diam.h Teupor.cpp Teupor.h Reumu.cpp Reumu.h Geurchar.cpp Geurchar.h CollisionEffect.h Streumon.cpp Streumon.h Oueurj.cpp Oueurj.h XStreumon.cpp XStreumon.h SStreumon.cpp SStreumon.h PStreumon.cpp PStreumon.h IStreumon.cpp IStreumon.h Teleportations.h MovingElement.h)