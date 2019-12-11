//
// Created by netbook on 10/12/2019.
//

#include "../headers/Teupor.h"

Teupor::Teupor() {

}

Teupor::Teupor(char s, Position &p, Board &b) : Element(s, p, b) {

}

bool Teupor::onCollision(Element &element) {
    return false;
}

Teupor::~Teupor() {

}
