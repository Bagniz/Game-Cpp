//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_TEUPOR_H
#define GAME_TEUPOR_H

#include "Element.h"
#include "CollisionEffect.h"

class Teupor : public Element, CollisionEffect
{
public:
    Teupor();
    Teupor(char symbole, Position &position, Board &board);
    bool onCollision(Element &element);
};


#endif //GAME_TEUPOR_H
