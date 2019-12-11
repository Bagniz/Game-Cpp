//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_XSTREUMON_H
#define GAME_XSTREUMON_H

#include "Element.h"
#include "CollisionEffect.h"
#include "MovingElement.h"

class XStreumon : public Element, CollisionEffect, MovingElement
{
public:
    XStreumon();
    XStreumon(char symbole, Position &position, Board &board);
    bool onCollision(Element &element);
    void move();
};


#endif //GAME_XSTREUMON_H
