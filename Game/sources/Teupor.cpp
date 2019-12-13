//
// Created by netbook on 10/12/2019.
//

#include "../headers/Teupor.h"

Teupor::Teupor() {

}

Teupor::Teupor(Position &p, Board &b) : Element('-', p, b) {
}

bool Teupor::onCollision(Element &element) {
    if(element.getSymbole()=='j'){
        if(this->getSymbole()=='+'){
            //win the board
            return true;
        }
    }
    return false;
}

Teupor::~Teupor() {

}
