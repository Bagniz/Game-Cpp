#include "../header/Position.h"

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const
{
    return this->x;
}

void Position::setX(int px)
{
    this->x = px;
}

int Position::getY() const
{
    return this->y;
}

void Position::setY(int py)
{
    this->y = py;
}

ostream &operator<<(ostream &flux, Position const &position)
{
    flux << "(" << position.getX() << "," << position.getY() << ")";
    return flux;
}

bool operator==(const Position &positionOne, const Position &positionTwo)
{
    return (positionOne.getX() == positionTwo.getX()) && (positionOne.getY() == positionTwo.getY());
}
