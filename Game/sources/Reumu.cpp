//
// Created by netbook on 10/12/2019.
//

#include "../headers/Reumu.h"

Reumu::Reumu() : Element() {}

Reumu::Reumu(char s, Position &p, Board &b) : Element(s,p,b) {}

bool Reumu::onCollision(Element & element)
{
    return false;
}
