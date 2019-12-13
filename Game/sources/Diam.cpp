//
// Created by netbook on 10/12/2019.
//

#include "../headers/Diam.h"

Diam::Diam() {

}

Diam::Diam(Position &p, Teupor &t, Board &b):teupor(t),Element('$', p, b){
}

bool Diam::onCollision(Element &element) {
    if(element.getSymbole()=='j'){
        this->teupor.setSymbole('+');
        this->board.removeElement(*this);
    }
    return true;
}

Diam::~Diam() {

}
