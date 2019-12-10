//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_ISTREUMON_H
#define GAME_ISTREUMON_H


#include "CollisionEffect.h"
#include "Element.h"
#include "MovingElement.h"

class IStreumon : public Element, CollisionEffect, MovingElement
{
public:
    IStreumon();
    IStreumon(Position position);
    bool onCollision(Element element);
    void move();
};


#endif //GAME_ISTREUMON_H
