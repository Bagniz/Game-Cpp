//
// Created by netbook on 10/12/2019.
//

#include "../headers/Element.h"

const Position &Element::getPosition() const {
    return position;
}

void Element::setPosition(const Position &position) {
    Element::position = position;
}

char Element::getSymbole() const {
    return symbole;
}
