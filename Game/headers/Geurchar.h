//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_GEURCHAR_H
#define GAME_GEURCHAR_H

#include "Element.h"
#include "CollisionEffect.h"
#include "Teleportations.h"

class Geurchar : public Element, CollisionEffect
{
private:
    Teleportations teleportation;
public:
    Geurchar();
    explicit Geurchar(char s, Position &p, Teleportations t, Board &b);
    bool onCollision(Element &element);
};

#endif //GAME_GEURCHAR_H
