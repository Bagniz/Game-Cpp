#include "../header/Diam.h"

Diam::Diam() : Element()
{
    this->symbole = '$';
    this->teupor = nullptr;
}

Diam::Diam(Position* p, Board *b) : Element(p,b)
{
    this->symbole = '$';
    this->teupor = nullptr;
}

Diam::Diam(Position* p, Teupor *t, Board *b) : Element(p,b)
{
    this->symbole = '$';
    this->teupor = t;
}

bool Diam::onCollision(Element *element)
{
    // If it a player
    if(element->getSymbole() == 'J')
    {
        // Open the port
        this->teupor->setSymbole('+');

        // Delete Element from the board
        this->board->removeElement(this);

        return true;
    }
    return false;
}

Teupor *Diam::getTeupor() const
{
    return this->teupor;
}

void Diam::setTeuport(Teupor *t)
{
    this->teupor = t;
}
