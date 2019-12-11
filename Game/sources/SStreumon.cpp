//
// Created by netbook on 10/12/2019.
//

#include "../headers/SStreumon.h"

SStreumon::SStreumon() {

}

SStreumon::SStreumon(char s, Position &p, Board &b) : Element(s, p, b) {

}

bool SStreumon::onCollision(Element &element) {
    return false;
}

void SStreumon::move() {

}

SStreumon::~SStreumon() {

}
