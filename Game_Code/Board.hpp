#ifndef BOARD // If the class Game is not defined
#define BOARD // the define the class Game as follows

#include <string>

class Board
{
    private:
        std::string boardName;
        int boardScore;

    public:
        Board(std::string name, int score = 0);
        void displayBoard();
};

#endif