#include "../header/Teupor.h"

Teupor::Teupor() : Element()
{
    this->symbole = '-';
}

Teupor::Teupor(Position *p, Board *b, bool isOpen) : Element(p, b)
{
    if(isOpen)
        this->symbole = '+';
    else
        this->symbole = '-';
}

bool Teupor::onCollision(Element *element)
{
    if(element->getSymbole() == 'J')
    {
        if(this->symbole == '+')
        {
            board->setBoardState(1);
            return true;
        }
    }
    return false;
}
