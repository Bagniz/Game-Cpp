//
// Created by netbook on 10/12/2019.
//

#include <iostream>
#include "../headers/Element.h"

Element::Element() : symbole(), position(), board() {}

Element::Element(char s, Position &p, Board &b) : symbole(s), position(p), board(b) {}

const Position &Element::getPosition() const
{
    return position;
}

void Element::setPosition(const Position &p)
{
    Element::position = p;
}

char Element::getSymbole() const
{
    return symbole;
}

void Element::setSymbole(char s)
{
    this->symbole = s;
}

Element::~Element()
{
    //cout << "Element " << this->symbole << " is deleted";
}

bool Element::onCollision(Element &element) {
    return true;
}
