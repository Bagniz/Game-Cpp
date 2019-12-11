//
// Created by netbook on 11/12/2019.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H


#include <string>
#include <vector>
#include "Element.h"


using namespace std;

class Board
{
private:
    string boardName;
    int boardScore;
    vector<vector<Element>> elements;

public:
    Board();
    Board(string name);
    void displayBoard();
    void boardSave();
};




#endif //GAME_BOARD_H
