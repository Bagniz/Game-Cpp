//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_SSTREUMON_H
#define GAME_SSTREUMON_H


#include "Element.h"
#include "CollisionEffect.h"
#include "MovingElement.h"

class SStreumon : public Element, CollisionEffect, MovingElement
{
public:
    SStreumon();
    SStreumon(Position position);
    bool onCollision(Element element);
    void move();
};


#endif //GAME_SSTREUMON_H
