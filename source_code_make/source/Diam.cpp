#include "../header/Diam.h"

Diam::Diam() : teupor(), Element()
{
    this->symbole = '$';
}

Diam::Diam(Position* p, Board *b) : teupor(nullptr), Element(p,b)
{
    this->symbole = '$';
}

Diam::Diam(Position* p, Teupor *t, Board *b) : teupor(t), Element(p,b)
{
    this->symbole = '$';
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
