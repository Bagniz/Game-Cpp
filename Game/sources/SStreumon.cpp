//
// Created by netbook on 10/12/2019.
//

#include <iostream>
#include "../headers/SStreumon.h"

SStreumon::SStreumon() {
    srand (time(NULL));
}

SStreumon::SStreumon(Position p, Board &b) : Element('s', p, b) {
    srand (time(NULL));
}

bool SStreumon::onCollision(Element &element) {
    if(element.getSymbole()=='j'){
        //game over
        return true;
    }
    return true;
}

void SStreumon::move() {
    int moveTo=rand()%8;
    Position newPosition;

    if(moveTo==0){
        newPosition = Position(this->position.getX() - 1, this->position.getY() - 1);
    } else if (moveTo==1){
        newPosition = Position(this->position.getX(), this->position.getY() - 1);
    } else if (moveTo==2){
        newPosition = Position(this->position.getX() + 1, this->position.getY() - 1);
    } else if (moveTo==3){
        newPosition = Position(this->position.getX() + 1, this->position.getY());
    } else if (moveTo==4){
        newPosition = Position(this->position.getX() + 1, this->position.getY() + 1);
    } else if (moveTo==5){
        newPosition = Position(this->position.getX(), this->position.getY() + 1);
    } else if (moveTo==6) {
        newPosition = Position(this->position.getX() - 1, this->position.getY() + 1);
    } else if (moveTo==7){
        newPosition = Position(this->position.getX() - 1, this->position.getY());
    }
    if(this->board->getElement(newPosition)->onCollision(*this)){
        this->board->moveElement(this->getPosition(),newPosition);
        this->position.setX(newPosition.getX());
        this->position.setY(newPosition.getY());
    }
}

SStreumon::~SStreumon() {

}
