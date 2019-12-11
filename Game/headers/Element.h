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
private:
    char symbole;
    Position position;
    Board board;

public:
    Element();
    Element(Position position);
    char getSymbole() const;
    const Position &getPosition() const;
    void setPosition(const Position &position);
};


#endif //GAME_ELEMENT_H
