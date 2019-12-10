//
// Created by netbook on 10/12/2019.
//

#include "Position.h"

Position::Position(int x, int y) : x(x), y(y)
{}

int Position::getX() const {
    return x;
}

void Position::setX(int x) {
    Position::x = x;
}

int Position::getY() const {
    return y;
}

void Position::setY(int y) {
    Position::y = y;
}
