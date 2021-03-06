#ifndef GAME_GEURCHAR_H
#define GAME_GEURCHAR_H

#include "Teleportations.h"
#include "Element.h"
#include "Oueurj.h"

class Geurchar : public Element
{
private:
    Teleportations teleportation;

public:
    Geurchar();
    Geurchar(Position* p, Teleportations t, Board* b);
    bool onCollision(Element *element);
    Teleportations getTeleportation() const;
};

#endif //GAME_GEURCHAR_H
