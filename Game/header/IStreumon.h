//
// Created by bagniz on 12/19/19.
//

#ifndef GAME_ISTREUMON_H
#define GAME_ISTREUMON_H

#include "MovingElement.h"
#include "Element.h"

class IStreumon : public Element, MovingElement
{
public:
    IStreumon();
    IStreumon(Position* p, Board* b);
    bool onCollision(Element* element);
    void move();
};

#endif //GAME_ISTREUMON_H
