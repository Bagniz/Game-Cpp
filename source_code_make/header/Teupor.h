#ifndef GAME_TEUPOR_H
#define GAME_TEUPOR_H

#include "Element.h"

class Teupor : public Element
{
public:
    Teupor();
    Teupor(Position* p, Board* b, bool isOpen);
    bool onCollision(Element* element);
};

#endif //GAME_TEUPOR_H
