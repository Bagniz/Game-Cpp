//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_REUMU_H
#define GAME_REUMU_H

#include "Element.h"
#include "CollisionEffect.h"

class Reumu : public Element, CollisionEffect
{
public:
    Reumu();
    Reumu(Position position);
    bool onCollision(Element element);
};


#endif //GAME_REUMU_H
