//
// Created by netbook on 11/12/2019.
//

#include <iostream>
#include <fstream>
#include "../headers/Board.h"
#include "../headers/Element.h"

Board::Board() {

}

bool Board::addElement(Element &element) {

    if(element.getPosition().getX()>this->elements.size()){
        this->elements.push_back({element});
    } else{
        this->elements[element.getPosition().getX()].push_back(element);
    }
    return true;
}

Board::Board(string name,int size) {
    for (int i = 0; i < size; ++i) {
        elements.emplace_back();
    }
}

bool Board::boardPlay() {

    while (endBoard == 0){
        //moving elements


        //updating superposed elements
        this->updateSuperposedElements();

        //printing the board
        this->displayBoard();
    }
    return endBoard == 1;
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
    for (auto i =elements.begin();i!=elements.end();++i) {
        for (auto j=i->begin();j!=i->end();++j) {
            std::cout<<j->getSymbole();
        }
        std::cout<<"\n";
    }
}

void Board::boardSave() {

    std::ofstream outfile ("boardName.board");

    for (auto i =elements.begin();i!=elements.end();++i) {
        for (auto j=i->begin();j!=i->end();++j) {
            outfile<<j->getSymbole();
        }
        outfile<<"\n";
    }

    outfile.close();

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

void Board::moveElement(Position oldPosition, Position newPosition) {

    //storing the superposed element
    if(this->getElement(newPosition).getSymbole()!=' '){
        this->superposedElements.push_back(this->getElement(newPosition));
    }
    //swaping the elements
    this->elements[newPosition.getX()][newPosition.getY()]=this->getElement(oldPosition);
    this->elements[oldPosition.getX()][oldPosition.getY()]=Element(' ',oldPosition, *this);
}

void Board::updateSuperposedElements() {
    //updating the non superposed elements any more

    for (int i =0;i < superposedElements.size(); i++) {
        if(this->getElement(superposedElements[i].getPosition()).getSymbole()==' '){
            int x=superposedElements[i].getPosition().getX();
            int y=superposedElements[i].getPosition().getX();
            this->elements[x][y]=superposedElements[i];

            superposedElements.erase(superposedElements.begin()+i);
            i--;
        }

    }

}
