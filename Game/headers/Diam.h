//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_DIAM_H
#define GAME_DIAM_H

#include "Element.h"
#include "CollisionEffect.h"
#include "Teupor.h"

class Diam : public Element, CollisionEffect
{
private:
    Teupor teupor;

public:
    Diam();
    Diam(char s, Position &p, Teupor &t, Board &b);
    bool onCollision(Element &element);
};


#endif //GAME_DIAM_H
