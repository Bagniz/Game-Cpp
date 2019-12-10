//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_DIAM_H
#define GAME_DIAM_H

#include "Element.h"
#include "CollisionEffect.h"

class Diam : public Element, CollisionEffect
{
public:
    Diam();
    Diam(Position position);
    bool onCollision(Element element);
};


#endif //GAME_DIAM_H
