//
// Created by bagniz on 12/19/19.
//

#include "../header/IStreumon.h"

IStreumon::IStreumon() : Element()
{
    this->symbole = 'I';
}

IStreumon::IStreumon(Position *p, Board *b) : Element(p, b)
{
    this->symbole = 'I';
}

bool IStreumon::onCollision(Element *element)
{
    if(element->getSymbole() == 'J')
    {
        board->setBoardStat(-2);
        return false;
    }
    return true;
}

void IStreumon::move()
{
    // TODO: IST MOVE
}
