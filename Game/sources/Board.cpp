//
// Created by netbook on 11/12/2019.
//

#include "../headers/Board.h"
#include "../headers/Element.h"

Board::Board() {

}

Board::Board(string name) {

}

bool Board::boardPlay() {

    while (endBoard == 0){
        //moving eleements update

        this->displayBoard();
    }
    if(endBoard == 1)
        return true;
    else
        return false;
}

void Board::boardEnd(bool isWinner) {
    if(isWinner)
        endBoard=1;
    else
        endBoard=-1;
}

void Board::displayBoard() {
    //system command to clean the previous version of the board
    system("clear");

    //double loop to print the board

}

void Board::boardSave() {

}

bool Board::addElement(Element &element) {
    return false;
}

bool Board::removeElement(Element &element) {
    return false;
}

string Board::getBoardName() {
    return std::__cxx11::string();
}

int Board::getBoardScore() {
    return 0;
}

Board::~Board() {

}

Element Board::getElement(const Position &position) {
    return this->elements[position.getY()][position.getX()];
}
