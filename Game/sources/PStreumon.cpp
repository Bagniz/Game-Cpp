//
// Created by netbook on 10/12/2019.
//

#include "../headers/PStreumon.h"

PStreumon::PStreumon() {

}

PStreumon::PStreumon(Position &p, Board *b) : Element('s', p, b) {

}

bool PStreumon::onCollision(Element &element) {
    return false;
}

void PStreumon::move() {

}

PStreumon::~PStreumon() {

}
