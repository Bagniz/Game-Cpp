//
// Created by netbook on 10/12/2019.
//

#include "../headers/Position.h"

Position::Position(int x, int y) : x(x), y(y)
{}

int Position::getX() const
{
    return x;
}

void Position::setX(int px)
{
    Position::x = px;
}

int Position::getY() const
{
    return y;
}

void Position::setY(int py)
{
    Position::y = py;
}

Position::~Position() {

}
