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
    vector<vector<Element*>> elements;

    //this attribute takes 0 is the game is still going 1 if the ouerj did win the board and -1 if the ouerj lost
    int endBoard=0;

    //this is a vector of superposed elements that means this vector is gonna be filled with elements that are super
    // posed by stremons so that we dont lose them after the stremons is gone
    vector<Element*> superposedElements ;
    //this is a vector to keep track of moving elements
    vector<Element*> movingElements;

public:
    Board();
    Board(string name,int size);

    bool boardPlay();
    void boardEnd(bool isWinner);
    void displayBoard();
    void boardSave();

    Element* getElement(const Position &position);
    bool addElement(Element *element);
    bool removeElement(Element *element);
    void moveElement(Position oldPosition,Position newPosition);
    void updateSuperposedElements();
    string getBoardName();
    int getBoardScore();

    vector<vector<Element*>> getElements;
    ~Board();
};




#endif //GAME_BOARD_H
