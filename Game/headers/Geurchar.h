//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_GEURCHAR_H
#define GAME_GEURCHAR_H

#include "Element.h"
#include "CollisionEffect.h"

class Geurchar : public Element, CollisionEffect
{
public:
    Geurchar();
    Geurchar(Position position);
    bool onCollision(Element element);
};


#endif //GAME_GEURCHAR_H
