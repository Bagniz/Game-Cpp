//
// Created by netbook on 11/12/2019.
//

#include <iostream>
#include <fstream>
#include "../headers/Board.h"
#include "../headers/Element.h"
#include "../headers/Oueurj.h"
#include "../headers/SStreumon.h"

Board::Board() {

}

Board::~Board() {

}

Board::Board(string name,int size) {

    for (int i = 0; i < size; ++i) {
        elements.emplace_back();

    }
}

bool Board::boardPlay() {

    int time=0;
    while (endBoard == 0 && time<2){
        //moving elements
        for (int i = 0; i < movingElements.size(); ++i) {
            Oueurj *j;
            SStreumon *s;
            if(movingElements[i]->getSymbole()=='j'){
                j = dynamic_cast<Oueurj*>(movingElements[i]);
                j->move();
            } else if (movingElements[i]->getSymbole()=='s'){
                s= dynamic_cast<SStreumon*>(movingElements[i]);
                s->move();
            }
        }
        //updating superposed elements
        this->updateSuperposedElements();

        //printing the board
        this->displayBoard();

        time++;
    }
    return endBoard == 1;
}

void Board::boardSave() {

    std::ofstream outfile ("boardName.board");

    for (auto i =elements.begin();i!=elements.end();++i) {
        for (auto j=i->begin();j!=i->end();++j) {
            outfile<<j.operator*()->getSymbole();
        }
        outfile<<"\n";
    }

    outfile.close();

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
            std::cout<<j.operator*()->getSymbole();//"("<<j.operator*()->getPosition().getX()<<"."<<j.operator*()->getPosition().getY()<<") ";
        }
        std::cout<<"\n";
    }
}

bool Board::addElement(Element &element) {

    this->elements[element.getPosition().getX()].emplace_back(&element);
    //[element.getPosition().getY()]=&element;
    if (element.getSymbole()=='j'||element.getSymbole()=='s'){
        movingElements.push_back(&element);
    }
    return true;
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

Element* Board::getElement(const Position &position) {
    return this->elements[position.getX()][position.getY()];
}

void Board::moveElement(Position oldPosition, Position newPosition) {
    cout<<"moving "<<getElement(oldPosition)->getSymbole()<<" to "<<getElement(newPosition)->getSymbole()<<endl;
    //storing the superposed element
    if(this->getElement(newPosition)->getSymbole()!=' '){
        this->superposedElements.push_back(this->getElement(newPosition));
    }
    //swaping the elements
    this->elements[newPosition.getX()][newPosition.getY()]=this->getElement(oldPosition);
    //Element e(' ',oldPosition, this);
    //this->elements[oldPosition.getX()][oldPosition.getY()]=&e;
}

void Board::updateSuperposedElements() {
    //updating the non superposed elements any more

    for (int i =0;i < superposedElements.size(); i++) {
        if(this->getElement(superposedElements[i]->getPosition())->getSymbole()==' '){
            int x=superposedElements[i]->getPosition().getX();
            int y=superposedElements[i]->getPosition().getX();
            this->elements[x][y]=superposedElements[i];

            superposedElements.erase(superposedElements.begin()+i);
            i--;
        }

    }

}
