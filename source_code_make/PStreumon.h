//
// Created by bagniz on 12/19/19.
//

#ifndef GAME_PSTREUMON_H
#define GAME_PSTREUMON_H

#include "Element.h"
#include "MovingElement.h"

class PStreumon : public Element, MovingElement
{
public:
    PStreumon();
    PStreumon(Position* p, Board* b);
    bool onCollision(Element* element) override;
    void move() override;
};

#endif //GAME_PSTREUMON_H
