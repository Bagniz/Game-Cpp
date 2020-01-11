#include <fstream>
#include <iomanip>
#include <utility>
#include <string>
#include <sstream>
#include "../header/Board.h"
#include "../header/Element.h"
#include "../header/Position.h"
#include "../header/Oueurj.h"
#include "../header/SStreumon.h"
#include "../header/PStreumon.h"
#include "../header/XStreumon.h"
#include "../header/Reumu.h"
#include "../header/IStreumon.h"
#include "../header/Diam.h"
#include "../header/Geurchar.h"

Board::Board() : boardState(0), playerXPosition(0), playerYPosition(0), boardName("") , playerScore{"", 0}{}

Board::Board(string boardName, const int width, const int height) : boardState(0), playerXPosition(0), playerYPosition(0), boardName(std::move(boardName)), playerScore{"", 0}
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

// Delete Board Save Files
void Board::deleteSaveBoardFiles(string playerName){
    string fileName = "./Boards/" + this->getBoardName() + playerName + ".board";
    remove(fileName.c_str());
}

int Board::boardPlay()
{
    Oueurj* oueurj = nullptr;
    vector<SStreumon*> sStreumon;
    vector<PStreumon*> pStreumon;
    vector<XStreumon*> xStreumon;
    vector<IStreumon*> iStreumon;

    for(Element* element : movingElements)
    {
        if(element->getSymbole() == 'J')
            oueurj = dynamic_cast<Oueurj*>(element);
        if(element->getSymbole() == 'S')
            sStreumon.emplace_back(dynamic_cast<SStreumon*>(element));
        if(element->getSymbole() == 'P')
            pStreumon.emplace_back(dynamic_cast<PStreumon*>(element));
        if(element->getSymbole() == 'M')
            xStreumon.emplace_back(dynamic_cast<XStreumon*>(element));
        if(element->getSymbole() == 'I')
            iStreumon.emplace_back(dynamic_cast<IStreumon*>(element));
    }
    do
    {
        this->displayBoard();
        if(oueurj != nullptr)
            oueurj->move();
        if(!sStreumon.empty()){
            for (SStreumon *s :sStreumon)
            {
                if(s!=nullptr)s->move();
            }
        }
        if(!pStreumon.empty()){
            for (PStreumon *p :pStreumon)
            {
                if(p!=nullptr)p->move();
            }
        }
        if(!xStreumon.empty()){
            for (XStreumon *x :xStreumon)
            {
                if(x!=nullptr)x->move();
            }
        }
        if(!iStreumon.empty()){
            for (IStreumon *i :iStreumon)
            {
                if(i!=nullptr)i->move();
            }
        }
    }while(this->boardState == 0);
    return this->boardState;
}

void Board::boardSave(bool saveToNew)
{
    // Open board file
    ofstream boardFile;
    if(saveToNew)
        boardFile.open("./Boards/" + this->boardName + this->getPlayerScore().playerName + ".board");
    else
        boardFile.open("./Boards/" + this->boardName + ".board");

    // Save board info
    boardFile << "width:" << this->boardElements[0].size() << endl;
    boardFile << "height:" << this->boardElements.size() << endl;
    boardFile << "name:" << this->boardName << endl;
    boardFile << "player:" << this->playerScore.playerName << endl;
    boardFile << "score:" << this->playerScore.playerScore << endl;

    // Save board Elements
    for(const vector<Element*>& ligneElements : boardElements)
    {
        for(Element* element : ligneElements)
        {
            if(element->getSymbole() == ' ')
                boardFile << '.' << ' ';
            else
            {
                if(element->getSymbole() != '*')
                {
                    boardFile << element->getSymbole() << ' ';
                }
                else
                {
                    auto* geurchar = dynamic_cast<Geurchar*>(element);
                    if(geurchar->getTeleportation() == Teleportations::RandomTeleportation)
                        boardFile << 'R' << ' ';
                    else if(geurchar->getTeleportation() == Teleportations::AxesTeleportation)
                        boardFile << 'A' << ' ';
                    else if(geurchar->getTeleportation() == Teleportations::PlaceTeleportation)
                        boardFile << 'C' << ' ';
                    else if(geurchar->getTeleportation() == Teleportations::SmartTeleportation)
                        boardFile << 'Q' << ' ';
                }
            }
        }
        boardFile << endl;
    }
    boardFile.close();
}

void Board::boardOver()
{
    // Clear the terminal
    system("clear");

    // Print messages depending on the game status
    switch (this->boardState)
    {
        case 1:
        {
            cout << "\tCongratulations you won the board" << endl;
            this->deleteSaveBoardFiles(this->getPlayerScore().playerName);
            break;
        }

        case -1:
        {
            char response;
            cout << "\nSorry to see you leave" << endl;
            cout << "Do you want to save the board for other time ?(Y/N)";
            cin >> response;
            if(response == 'Y' || response == 'y')
            {
                this->boardSave(true);
                cout << "The board is saved" << endl;
            }
            else
                cout << "The board did not save." << endl;
            break;
        }

        case -2:
        {
            cout << "\nYou lost!!!!" << endl;
            this->deleteSaveBoardFiles(this->getPlayerScore().playerName);
            break;
        }

        default:
            throw bad_exception();
    }
}

Board *Board::boardLoad(const string& name)
{
    Board* board = nullptr;
    // Open board file
    ifstream boardFile("./Boards/" + name + ".board");

    if(boardFile.is_open())
    {
        string word, key, value, boardName;
        int counter = 1, boardWidth = 0, boardHeight = 0, boardState = 0;
        Score playerScore;

        // Get the board information
        while(counter < 6 && getline(boardFile, word, '\n'))
        {
            // Get the key and the value of the line
            key = word.substr(0, word.find(':'));
            value = word.substr(word.find(':') + 1, word.size());

            // Get the value depending of the key
            if(key == "width")
                boardWidth = stoi(value);
            else if(key == "height")
                boardHeight = stoi(value);
            else if(key == "name")
                boardName = value;
            else if(key == "player")
                playerScore.playerName = value;
            else if(key == "score")
                playerScore.playerScore = stoi(value);
            counter++;
        }

        // Create the board
        board = new Board(boardName, boardWidth, boardHeight);
        board->setBoardState(boardState);
        board->setBoardScore(playerScore);

        // Get the board elements
        int i = 0, j = 0;
        vector<Teupor*> ports;
        vector<Diam*> diams;
        while(getline(boardFile, word, ' '))
        {
            if(word == ".") // Element
                board->addElement(new Element(new Position(i, j), board));
            else if(word == "J") // Oueurj
            {
                board->addElement(new Oueurj(new Position(i, j), board));
                board->setPlayerXPosition(i);
                board->setPlayerYPosition(j);
            }
            else if(word == "S") // SStreumon
                board->addElement(new SStreumon(new Position(i, j), board));
            else if(word == "P") // PStreumon
                board->addElement(new PStreumon(new Position(i, j), board));
            else if(word == "M") // XStreumon
                board->addElement(new XStreumon(new Position(i, j), board));
            else if(word == "I") // IStreumon
                board->addElement(new IStreumon(new Position(i, j), board));
            else if(word == "$") // Diam
            {
                auto* diam = new Diam(new Position(i, j), board);
                diams.emplace_back(diam);
                board->addElement(diam);
            }
            else if(word == "-" || word == "+" || word == "\n-"|| word == "\n+") // Teupor
            {
                Teupor* port = nullptr;
                if(word == "-" || word == "\n-")
                {
                    port = new Teupor(new Position(i, j), board, false);
                    ports.emplace_back(port);
                }
                else
                    port = new Teupor(new Position(i, j), board, true);
                board->addElement(port);
            }
            else if(word == "X" || word == "\nX") // Reumu
                board->addElement(new Reumu(new Position(i, j), board));
            else if(word == "R") // Geurchar
                board->addElement(new Geurchar(new Position(i, j), Teleportations::RandomTeleportation,board));
            else if(word == "A") // Geurchar
                board->addElement(new Geurchar(new Position(i, j), Teleportations::AxesTeleportation,board));
            else if(word == "C") // Geurchar
                board->addElement(new Geurchar(new Position(i, j), Teleportations::PlaceTeleportation,board));
            else if(word == "Q") // Geurchar
                board->addElement(new Geurchar(new Position(i, j), Teleportations::SmartTeleportation,board));

            // Go to the next line
            if(++j == boardWidth)
            {
                j = 0;
                i++;
            }
        }

        // Link diam and port
        for(unsigned n = 0; n < ports.size(); n++)
            diams.at(n)->setTeuport(ports.at(n));

        // Close the file
        boardFile.close();
    }
    return board;
}

bool Board::addElement(Element *element)
{
    // Add the new element
    this->boardElements[element->getPosition()->getX()][element->getPosition()->getY()] = element;
    if((element->getSymbole() == 'S') || (element->getSymbole() == 'J') || (element->getSymbole() == 'P') || (element->getSymbole() == 'M') || (element->getSymbole() == 'I'))
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


void Board::setPlayerXPosition(int x){
    this->playerXPosition = x;
}

void Board::setPlayerYPosition(int y){
    this->playerYPosition = y;
}

void Board::displayBoard() const
{
    // System command to clean terminal
    system("clear");

    // Print the board //
    int counter = 0;
    
    // coordinates
    unsigned x = 0, y = 0;
    
    // Print Y coordinates
    cout << "  ";
    for (y = 0; y < this->boardElements[0].size(); y++)
        cout << setw(2) << y;
    cout<<endl;

    // Print other elements
    for(const vector<Element*>& ligneElements : boardElements)
    {
        // Print X coordinates
        cout << setw(2) << x << ' ';
        x++;

        // Display elements
        for(Element* element : ligneElements)
            cout << element->getSymbole() << ' ';

        // Print board info
        if(counter == 0)
            cout << "\tboard: " << this->getBoardName();
        else if(counter == 1)
            cout << "\tplayer: " << this->getPlayerScore().playerName;
        else if(counter == 2)
            cout << "\tscore: " << this->getPlayerScore().playerScore;
        else if(counter == 3)
            cout << "\tplayer position x: " << this->playerXPosition;
        else if(counter == 4)
            cout << "\tplayer position y: " << this->playerYPosition;
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

void Board::setBoardState(int state)
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

void Board::setBoardScore(Score& score)
{
    this->playerScore = score;
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
