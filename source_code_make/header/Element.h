#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include "Position.h"
#include "Board.h"

class Element
{
protected:
    char symbole = ' ';
    Position* position;
    Board* board;

public:
    Element();
    Element(Position* position, Board* board);
    char getSymbole() const;
    void setSymbole(char s);
    Position* getPosition() const;
    void setPosition(Position* p);
    virtual bool onCollision(Element* element);
    virtual ~Element();
};

#endif //GAME_ELEMENT_H
