//
// Created by bagniz on 12/19/19.
//

#include "../header/Element.h"

Element::Element() : position(), board() {}

Element::Element(Position* position, Board* board) : position(position), board(board) {}

char Element::getSymbole() const
{
    return this->symbole;
}

void Element::setSymbole(char s)
{
    this->symbole = s;
}

Position *Element::getPosition() const
{
    return this->position;
}

void Element::setPosition(Position *p)
{
    this->position = p;
}

bool Element::onCollision(Element* element)
{
    // Always let the other element pass
    return true;
}

Element::~Element()
{
    delete position;
}
