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
    explicit Geurchar(Position &p, Teleportations t, Board &b);
    bool onCollision(Element &element);
    ~Geurchar();
};

#endif //GAME_GEURCHAR_H
