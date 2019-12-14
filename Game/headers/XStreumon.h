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
    XStreumon(Position &p, Board *b);
    bool onCollision(Element &element);
    void move();
    ~XStreumon();
};


#endif //GAME_XSTREUMON_H
