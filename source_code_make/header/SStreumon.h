#ifndef GAME_SSTREUMON_H
#define GAME_SSTREUMON_H

#include "Element.h"
#include "MovingElement.h"

class SStreumon : public Element, MovingElement
{
public:
    SStreumon();
    SStreumon(Position* p, Board* b);
    bool onCollision(Element* element) override;
    void move() override;
};

#endif //GAME_SSTREUMON_H
