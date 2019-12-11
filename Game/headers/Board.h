//
// Created by netbook on 11/12/2019.
//

#ifndef GAME_BOARD_H
#define GAME_BOARD_H


#include <string>
#include <vector>
#include "Position.h"


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
    bool removeElement(Element &element);
    Element getElement(const Position &position);
    string getBoardName();
    int getBoardScore();
    vector<vector<Element>> getElements;
    ~Board();
};




#endif //GAME_BOARD_H
