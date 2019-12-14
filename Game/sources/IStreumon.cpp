//
// Created by netbook on 10/12/2019.
//

#include "../headers/IStreumon.h"

IStreumon::IStreumon() {

}

IStreumon::IStreumon(Position &p, Board *b) : Element('s', p, b) {

}

bool IStreumon::onCollision(Element &element) {
    return false;
}

void IStreumon::move() {

}

IStreumon::~IStreumon() {

}
