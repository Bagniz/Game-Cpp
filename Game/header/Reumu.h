//
// Created by bagniz on 12/19/19.
//

#ifndef GAME_REUMU_H
#define GAME_REUMU_H


#include "Element.h"

class Reumu : public Element
{
public:
    Reumu();
    Reumu(Position* p, Board* b);
    bool onCollision(Element* element);
};


#endif //GAME_REUMU_H
