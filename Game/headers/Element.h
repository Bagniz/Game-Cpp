//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include "Position.h"
#include "Board.h"

using namespace std;

class Element
{
protected:
    char symbole;
    Position position;
    Board board;

public:
    Element();
    Element(char s, Position &p, Board &b);
    char getSymbole() const;
    void setSymbole(char s);
    const Position &getPosition() const;
    void setPosition(const Position &p);
    virtual ~Element();
};

#endif //GAME_ELEMENT_H
