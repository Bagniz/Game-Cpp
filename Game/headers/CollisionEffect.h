//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_COLLISIONEFFECT_H
#define GAME_COLLISIONEFFECT_H

#include "Element.h"

class CollisionEffect
{
    virtual bool onCollision(Element element) = 0;
};

#endif //GAME_COLLISIONEFFECT_H
