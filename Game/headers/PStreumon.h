//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_PSTREUMON_H
#define GAME_PSTREUMON_H

#include "Element.h"
#include "CollisionEffect.h"
#include "MovingElement.h"

class PStreumon : public Element, CollisionEffect, MovingElement
{
public:
    PStreumon();
    PStreumon(Position p, Board &b);
    bool onCollision(Element &element);
    void move();
    ~PStreumon();
};


#endif //GAME_PSTREUMON_H
