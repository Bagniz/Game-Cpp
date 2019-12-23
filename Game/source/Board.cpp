//
// Created by bagniz on 12/19/19.
//

#include <fstream>
#include <utility>
#include <thread>
#include <string>
#include <sstream>
#include <regex>
#include "../header/Board.h"
#include "../header/Element.h"
#include "../header/Position.h"
#include "../header/Oueurj.h"
#include "../header/SStreumon.h"
#include "../header/PStreumon.h"
#include "../header/XStreumon.h"
#include "../header/Reumu.h"
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
            oueurj = dynamic_cast<Oueurj*>(element);
        if(element->getSymbole() == 'S')
            sStreumon = dynamic_cast<SStreumon*>(element);
        if(element->getSymbole() == 'P')
            pStreumon = dynamic_cast<PStreumon*>(element);
        if(element->getSymbole() == 'M')
            xStreumon = dynamic_cast<XStreumon*>(element);
        if(element->getSymbole() == 'I')
            iStreumon = dynamic_cast<IStreumon*>(element);
    }
    do
    {
        this->displayBoard();
        if(oueurj != nullptr)
            oueurj->move();
        if(sStreumon != nullptr)
            sStreumon->move();
        if(pStreumon != nullptr)
            pStreumon->move();
        if(xStreumon != nullptr)
            xStreumon->move();
        if(iStreumon != nullptr)
            iStreumon->move();
    }while(this->boardState == 0);
    return boardState;
}

void Board::boardSave()
{
    // Open board file
    ofstream boardFile(this->boardName + ".board");

    // Save board info
    boardFile << "width:" << this->boardElements[0].size() << endl;
    boardFile << "height" << this->boardElements.size() << endl;
    boardFile << "name:" << this->boardName << endl;
    boardFile << "player:" << this->playerScore.playerName << endl;
    boardFile << "score:" << this->playerScore.playerScore << endl;
    boardFile << "state:" << this->boardState << endl;

    // Save board Elements
    for(const vector<Element*>& ligneElements : boardElements)
    {
        for(Element* element : ligneElements)
        {
            if(element->getSymbole() == ' ')
                boardFile << '.' << ' ';
            else
                boardFile << element->getSymbole() << ' ';
        }
        boardFile << endl;
    }
    boardFile.close();
}

Board *Board::boardLoad(const string& name)
{
    Board* board = nullptr;
    ifstream boardFile(name + ".board");
    if(boardFile.is_open())
    {
        board = new Board("",0,0);
        string word, key, value;
        int counter = 0;

        // Get the board information
        while(counter < 4 && getline(boardFile, word, '\n'))
        {
            key = word.substr(0, word.find(':') - 1);
            value = word.substr(word.find(':') + 1, word.size());
            if(key == "state")
                board->boardState = stoi(value);
            else if(key == "name")
                board->boardName = value;
            else if(key == "player")
                board->playerScore.playerName = value;
            else if(key == "score")
                board->playerScore.playerScore = stoi(value);
            counter++;
        }

        // Get the board elements
        while(getline(boardFile, word, ' '))
        {

        }

        // Close the file
        boardFile.close();
    }
    return board;
}

bool Board::addElement(Element *element)
{
    // Add the new element
    this->boardElements[element->getPosition()->getX()][element->getPosition()->getY()] = element;
    if((element->getSymbole() == 'S') || (element->getSymbole() == 'J') || (element->getSymbole() == 'P') || (element->getSymbole() == 'M'))
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
