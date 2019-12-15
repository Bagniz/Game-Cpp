//
// Created by netbook on 10/12/2019.
//

#include "../headers/XStreumon.h"

XStreumon::XStreumon() {

}

XStreumon::XStreumon(Position p, Board &b) : Element('s', p, b) {

}

bool XStreumon::onCollision(Element &element) {
    return false;
}

void XStreumon::move() {

}

XStreumon::~XStreumon() {

}
