CPP=g++ --std=c++11 -Wall

all: gp gc clean

gc: Game.o Board.o Element.o clicked_char.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o
	$(CPP) -o gc Game.o Board.o Element.o clicked_char.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o	

gp: Game.o Board.o Element.o clicked_char.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o
	$(CPP) -o gp Game.o Board.o Element.o clicked_char.o Teupor.o Diam.o Reumu.o Geurchar.o Oueurj.o SStreumon.o PStreumon.o XStreumon.o IStreumon.o main.o Position.o	

main.o: main.cpp
	$(CPP) -c main.cpp

Position.o: Position.h Position.cpp
	$(CPP) -c Position.cpp

Game.o: Game.h Game.cpp
	$(CPP) -c Game.cpp

Board.o: Board.h Board.cpp
	$(CPP) -c Board.cpp

Diam.o: Diam.h Diam.cpp
	$(CPP) -c Diam.cpp

SStreumon.o: SStreumon.h SStreumon.cpp 
	$(CPP) -c SStreumon.cpp PStreumon.cpp XStreumon.cpp IStreumon.cpp

PStreumon.o: PStreumon.h PStreumon.cpp
	$(CPP) -c PStreumon.cpp

XStreumon.o: XStreumon.h XStreumon.cpp
	$(CPP) -c XStreumon.cpp

IStreumon.o: IStreumon.h IStreumon.cpp
	$(CPP) -c IStreumon.cpp

Teupor.o: Teupor.h Teupor.cpp
	$(CPP) -c Teupor.cpp

Geurchar.o: Geurchar.h Geurchar.cpp
	$(CPP) -c Geurchar.cpp

Oueurj.o: Oueurj.h Oueurj.cpp
	$(CPP) -c Oueurj.cpp

Reumu.o: Reumu.h Reumu.cpp
	$(CPP) -c Reumu.cpp

Element.o: Element.h Element.cpp
	$(CPP) -c Element.cpp

clicked_char.o: clicked_char.h clicked_char.cpp
	$(CPP) -c clicked_char.cpp

clean:
	rm *.o