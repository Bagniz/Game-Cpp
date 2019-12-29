#include "../header/Reumu.h"

Reumu::Reumu() : Element()
{
    this->symbole = 'X';
}

Reumu::Reumu(Position *p, Board *b) : Element(p, b)
{
    this->symbole = 'X';
}

bool Reumu::onCollision(Element *element)
{
    return false;
}
