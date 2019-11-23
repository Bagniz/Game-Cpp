CPP=g++ --std=c++11 -Wall

all: gp gc clean

gp: game.o board.o gamePlayerMain.o
	$(CPP) -o gp Board.o Game.o GamePlayer.o 

board.o: Board.hpp Board.cpp
	$(CPP) -c Board.cpp

game.o: Game.hpp Game.cpp
	$(CPP) -c Game.cpp

gamePlayerMain.o: GamePlayer.cpp
	$(CPP) -c GamePlayer.cpp

gc: gameCreatorMain.o
	$(CPP) -o gc GameCreator.o

gameCreatorMain.o: GameCreator.cpp
	$(CPP) -c GameCreator.cpp

clean: 
	rm *.o
