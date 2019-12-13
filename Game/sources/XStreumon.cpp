//
// Created by netbook on 10/12/2019.
//

#include "../headers/XStreumon.h"

XStreumon::XStreumon() {

}

XStreumon::XStreumon(char s, Position &p, Board &b) : Element('s', p, b) {

}

bool XStreumon::onCollision(Element &element) {
    return false;
}

void XStreumon::move() {

}

XStreumon::~XStreumon() {

}
