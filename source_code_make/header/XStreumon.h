#ifndef GAME_XSTREUMON_H
#define GAME_XSTREUMON_H

#include "Element.h"
#include "MovingElement.h"

class XStreumon : public Element, MovingElement
{
public:
    XStreumon();
    XStreumon(Position* p, Board* b);
    bool onCollision(Element* element) override;
    void move() override;
};

#endif //GAME_XSTREUMON_H
