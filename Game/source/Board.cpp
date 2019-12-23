//
// Created by bagniz on 12/19/19.
//

#include <fstream>
#include <utility>
#include <thread>
#include "../header/Board.h"
#include "../header/Element.h"
#include "../header/Position.h"
#include "../header/Oueurj.h"
#include "../header/SStreumon.h"
#include "../header/PStreumon.h"
#include "../header/XStreumon.h"
#include "../header/IStreumon.h"


Board::Board() : boardName(""), boardState(0){}

Board::Board(string boardName, const int width, const int height) : boardName(std::move(boardName)), boardState(0)
{
    for (int i = 0; i < height; ++i)
    {
        this->boardElements.emplace_back();
        for (int j = 0; j < width; ++j)
        {
            this->boardElements[i].emplace_back(new Element(new Position(i,j), this));
        }
    }
}

int Board::boardPlay()
{
    Oueurj* oueurj = nullptr;
    SStreumon* sStreumon = nullptr;
    PStreumon* pStreumon = nullptr;
    XStreumon* xStreumon = nullptr;
    IStreumon* iStreumon = nullptr;

    for(Element* element : movingElements)
    {
        if(element->getSymbole() == 'J')
        {
            oueurj = dynamic_cast<Oueurj*>(element);
        }
        else if(element->getSymbole() == 'S')
        {
            sStreumon = dynamic_cast<SStreumon*>(element);
        }
        else if(element->getSymbole() == 'P')
        {
            pStreumon = dynamic_cast<PStreumon*>(element);
        }
        else if(element->getSymbole() == 'M')
        {
            xStreumon = dynamic_cast<XStreumon*>(element);
        }
        else if(element->getSymbole() == 'I')
        {
            iStreumon = dynamic_cast<IStreumon*>(element);
        }
    }
    do
    {
        this->displayBoard();
        oueurj->move();
        sStreumon->move();
        pStreumon->move();
        xStreumon->move();
        iStreumon->move();
//        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }while(this->boardState == 0);
    return boardState;
}

void Board::boardSave()
{
    // Open board file
    ofstream boardFile(this->boardName + ".board");

    // Save board info
    boardFile << "name:" << this->boardName << endl;
    boardFile << "player:" << this->playerScore.playerName << ",score:" << this->playerScore.playerScore << endl;

    // Save board Elements
    for(const vector<Element*>& ligneElements : boardElements)
    {
        for(Element* element : ligneElements)
            boardFile << element->getSymbole();
        boardFile << endl;
    }

    boardFile.close();
}

Board *Board::boardLoad(string name)
{
    // TODO : BOARD LOAD
    return nullptr;
}

bool Board::addElement(Element *element)
{
    // Add the new element
    this->boardElements[element->getPosition()->getX()][element->getPosition()->getY()] = element;
    if((element->getSymbole() == 'S') || (element->getSymbole() == 'J') || (element->getSymbole() == 'P')|| (element->getSymbole() == 'I') || (element->getSymbole() == 'M'))
        this->movingElements.emplace_back(element);
    return true;
}

bool Board::removeElement(Element *element)
{
    Element* elementToDelete = this->boardElements[element->getPosition()->getX()][element->getPosition()->getY()];

    // Add the new void element
    this->boardElements[element->getPosition()->getX()][element->getPosition()->getY()] = new Element(new Position(element->getPosition()->getX(), element->getPosition()->getY()), this);

    // Delete the previous
    delete elementToDelete;

    return true;
}

void Board::moveElement(Position* oldPosition, Position* newPosition)
{
    Element* newPositionElement = this->getElement(newPosition);
    Element* oldPositionElement = this->getElement(oldPosition);
    if(newPositionElement->getSymbole() == ' ')
    {
        oldPositionElement->setPosition(newPosition);
        this->addElement(oldPositionElement);
        newPositionElement->setPosition(oldPosition);
        this->addElement(newPositionElement);
    }
    else
    {
        delete newPositionElement;
        oldPositionElement->setPosition(newPosition);
        this->addElement(oldPositionElement);
        this->addElement(new Element(oldPosition, this));
    }
}

void Board::displayBoard() const
{
    // System command to clean terminal
    system("clear");

    // Print the board
    int counter = 0;
    for(const vector<Element*>& ligneElements : boardElements)
    {
        // Display elements
        for(Element* element : ligneElements)
            cout << element->getSymbole() << ' ';

        // Print board info
        if(counter == 1)
        {
            cout << "\tboard : " << this->getBoardName();
        }
        else if(counter == 2)
        {
            cout << "\tplayer : " << this->getPlayerScore().playerName;
        }
        else if(counter == 3)
        {
            cout << "\tscore : " << this->getPlayerScore().playerScore;

        }
        cout << endl;
        counter++;
    }
}

Element *Board::getElement(const Position* position)
{
    return this->boardElements[position->getX()][position->getY()];
}

int Board::getBoardState()
{
    return this->boardState;
}

void Board::setBoardStat(int state)
{
    this->boardState = state;
}

string Board::getBoardName() const
{
    return this->boardName;
}

Score Board::getPlayerScore() const
{
    return this->playerScore;
}

vector<vector<Element *>> Board::getBoardElements()
{
    return this->boardElements;
}

Board::~Board()
{
    for(const vector<Element*>& ligneElements : boardElements)
    {
        for(Element* element : ligneElements)
            delete element;
    }
}
