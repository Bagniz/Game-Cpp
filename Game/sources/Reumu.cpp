//
// Created by netbook on 10/12/2019.
//

#include "../headers/Reumu.h"

Reumu::Reumu() : Element() {}

Reumu::Reumu(Position p, Board &b) : Element('x',p,b) {}

bool Reumu::onCollision(Element & element)
{
    return false;
}

Reumu::~Reumu() {

}
