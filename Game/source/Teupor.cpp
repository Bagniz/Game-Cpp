//
// Created by bagniz on 12/19/19.
//

#include "../header/Teupor.h"

Teupor::Teupor() : Element()
{
    this->symbole = '-';
}

Teupor::Teupor(Position *p, Board *b) : Element(p, b)
{
    this->symbole = '-';
}

bool Teupor::onCollision(Element *element)
{
    if(element->getSymbole() == 'J')
    {
        if(this->symbole == '+')
        {
            board->setBoardStat(1);
            return true;
        }
    }
    return false;
}
