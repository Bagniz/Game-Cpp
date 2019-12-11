//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <string>
#include <vector>

using namespace std;

class Element;

class Board
{
private:
    string boardName;
    int boardScore;
    vector<vector<Element>> elements;

public:
    Board();
    Board(string name);
    bool boardPlay();
    void displayBoard();
    void boardSave();
    bool addElement(Element &element);
};


#endif //GAME_BOARD_H
