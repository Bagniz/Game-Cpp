CPP=g++ --std=c++11 -Wall

all: gp gc clean

gc: Game.o Board.o Element.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o
	$(CPP) -o gc Game.o Board.o Element.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o	

gp: Game.o Board.o Element.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o
	$(CPP) -o gp Game.o Board.o Element.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o	

main.o: main.cpp
	$(CPP) -c main.cpp

Position.o: header/Position.h source/Position.cpp
	$(CPP) -c source/Position.cpp

Game.o: header/Game.h source/Game.cpp
	$(CPP) -c source/Game.cpp

Board.o: header/Board.h source/Board.cpp
	$(CPP) -c source/Board.cpp

Diam.o: header/Diam.h source/Diam.cpp
	$(CPP) -c source/Diam.cpp

SStreumon.o: header/SStreumon.h source/SStreumon.cpp 
	$(CPP) -c source/SStreumon.cpp

PStreumon.o: header/PStreumon.h source/PStreumon.cpp
	$(CPP) -c source/PStreumon.cpp

XStreumon.o: header/XStreumon.h source/XStreumon.cpp
	$(CPP) -c source/XStreumon.cpp

IStreumon.o: header/IStreumon.h source/IStreumon.cpp
	$(CPP) -c source/IStreumon.cpp

Teupor.o: header/Teupor.h source/Teupor.cpp
	$(CPP) -c source/Teupor.cpp

Geurchar.o: header/Geurchar.h source/Geurchar.cpp
	$(CPP) -c source/Geurchar.cpp

Oueurj.o: header/Oueurj.h source/Oueurj.cpp
	$(CPP) -c source/Oueurj.cpp

Reumu.o: header/Reumu.h source/Reumu.cpp
	$(CPP) -c source/Reumu.cpp

Element.o: header/Element.h source/Element.cpp
	$(CPP) -c source/Element.cpp

clean:
	rm *.o