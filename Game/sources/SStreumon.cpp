//
// Created by netbook on 10/12/2019.
//

#include "../headers/SStreumon.h"

SStreumon::SStreumon() {
    srand (time(NULL));
}

SStreumon::SStreumon(char s, Position &p, Board &b) : Element(s, p, b) {
    srand (time(NULL));
}

bool SStreumon::onCollision(Element &element) {

    return false;
}

void SStreumon::move() {
    long moveTo=random()%8;
    Position newPosition;
    switch (moveTo){
        case 0:
            newPosition = Position(this->position.getX() - 1, this->position.getY() - 1);
        case 1:
            newPosition = Position(this->position.getX(), this->position.getY() - 1);
        case 2:
            newPosition = Position(this->position.getX() + 1, this->position.getY() - 1);
        case 3:
            newPosition = Position(this->position.getX() + 1, this->position.getY());
        case 4:
            newPosition = Position(this->position.getX() + 1, this->position.getY() + 1);
        case 5:
            newPosition = Position(this->position.getX(), this->position.getY() + 1);
        case 6:
            newPosition = Position(this->position.getX() - 1, this->position.getY() + 1);
        case 7:
            newPosition = Position(this->position.getX() - 1, this->position.getY());
        default:
            newPosition = Position(this->position.getX(), this->position.getY());
    };
    if(this->board.getElement(newPosition).getSymbole()!='X'){
        this->position=newPosition;
    }
}

SStreumon::~SStreumon() {

}
