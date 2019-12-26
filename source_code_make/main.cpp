#include <iostream>
#include <fstream>
#include <algorithm>
#include "Board.h"
#include "Oueurj.h"
#include "Reumu.h"
#include "Teupor.h"
#include "Diam.h"
#include "Geurchar.h"
#include "SStreumon.h"
#include "PStreumon.h"
#include "XStreumon.h"
#include "IStreumon.h"

using namespace std;

// Create a board
void createBoard(const string& boardName)
{
    /////////////// Create a board /////////////////////
    int boardWidth, boardHeight, elementChoice = 0, xPosition = 0, yPosition = 0;

    // Starting to create the board
    cout << "Creating board: " << boardName << endl;

    // Get board dimensions
    cout << "Please enter board width:";
    cin >> boardWidth;
    cout << "Please enter board height:";
    cin >> boardHeight;

    // Create the board
    auto* board = new Board(boardName, boardWidth, boardHeight);

    // Adding the walls
    for(const vector<Element*>& ligne : board->getBoardElements())
        for(Element* element : ligne)
            if((element->getPosition()->getX() == 0) || (element->getPosition()->getX() == 19) || (element->getPosition()->getY() == 0) || (element->getPosition()->getY() == 19))
                board->addElement(new Reumu(element->getPosition(), board));

    // Create board Elements
    do
    {
        // Choose which element to add
        cout << "Which element do you want to add" << endl;
        cout << "1. Reumu" << endl;
        cout << "2. Diam" << endl;
        cout << "3. Teupor" << endl;
        cout << "4. Geurchar" << endl;
        cout << "5. SStreumon" << endl;
        cout << "6. XStreumon" << endl;
        cout << "7. PStreumon" << endl;
        cout << "8. IStreumon" << endl;
        cout << "0. Cancel" << endl;
        cout << "Element number: ";
        cin >> elementChoice;

        if(elementChoice == 0)
            break;
        else
        {
            // Enter the elements position
            cout << "Please enter the elements position:" << endl;
            cout << "X:";
            cin >> xPosition;
            cout << "Y:";
            cin >> yPosition;

            if(elementChoice != 3)
            {
                while(((xPosition == 0) || (xPosition == boardHeight)) || ((yPosition != 0) || (yPosition != boardWidth)))
                {
                    cout << "\t\tInvalid entered position" << endl;
                    cout << "Please enter the elements position:" << endl;
                    cout << "X:";
                    cin >> xPosition;
                    cout << "Y:";
                    cin >> yPosition;
                }

                if(elementChoice == 1)
                    board->addElement(new Reumu(new Position(xPosition, yPosition), board));
                else if(elementChoice == 2)
                {
                    int txPosition, tyPosition;
                    cout << "Please enter the position of teupor associated with this diam:" << endl;
                    cout << "X:";
                    cin >> txPosition;
                    cout << "Y:";
                    cin >> tyPosition;
                    while((xPosition != 0) && (xPosition != boardHeight) && (yPosition != 0) && (yPosition != boardWidth))
                    {
                        cout << "\t\tInvalid entered position" << endl;
                        cout << "Please enter the position of teupor associated with this diam:" << endl;
                        cout << "X:";
                        cin >> txPosition;
                        cout << "Y:";
                        cin >> tyPosition;
                    }
                    board->addElement(new Diam(new Position(xPosition, yPosition), new Teupor(new Position(txPosition, tyPosition), board), board));
                }
                else if(elementChoice == 4)
                {
                    int teleportationType;
                    do
                    {
                        cout << "Please choose the type of the teleporation given by the geurchar:" << endl;
                        cout << "1. Random Teleporation" << endl;
                        cout << "2. Place Teleportation" << endl;
                        cout << "3. Axes Teleportation" << endl;
                        cout << "4. Smart Teleportation" << endl;
                        cout << "Teleporation number: ";
                        cin >> teleportationType;
                        switch (teleportationType)
                        {
                            case 1:
                            {
                                board->addElement(new Geurchar(new Position(xPosition, yPosition), Teleportations::RandomTeleportation, board));
                                break;
                            }

                            case 2:
                            {
                                board->addElement(new Geurchar(new Position(xPosition, yPosition), Teleportations::PlaceTeleportation, board));
                                break;
                            }

                            case 3:
                            {
                                board->addElement(new Geurchar(new Position(xPosition, yPosition), Teleportations::AxesTeleportation, board));
                                break;
                            }

                            case 4:
                            {
                                board->addElement(new Geurchar(new Position(xPosition, yPosition), Teleportations::SmartTeleportation, board));
                                break;
                            }
                            default:
                                continue;
                        }
                    }while((teleportationType > 4) || (teleportationType < 1));
                }
                else if(elementChoice == 5)
                    board->addElement(new SStreumon(new Position(xPosition, yPosition), board));
                else if(elementChoice == 6)
                    board->addElement(new XStreumon(new Position(xPosition, yPosition), board));
                else if(elementChoice == 7)
                    board->addElement(new PStreumon(new Position(xPosition, yPosition), board));
                else if(elementChoice == 8)
                    board->addElement(new IStreumon(new Position(xPosition, yPosition), board));
            }
            else // Element choice == 3
            {
                while((xPosition != 0) && (xPosition != boardHeight) && (yPosition != 0) && (yPosition != boardWidth))
                {
                    cout << "\t\tInvalid entered position" << endl;
                    cout << "Please enter the elements position:" << endl;
                    cout << "X:";
                    cin >> xPosition;
                    cout << "Y:";
                    cin >> yPosition;
                }
                board->addElement(new Teupor(new Position(xPosition, yPosition), board));
            }
        }
    }while(elementChoice != 0);
    board->boardSave();
}

// Create a game app
bool gameCreate(int argc, char** argv)
{
    cout << "\tWelcome to Creator Mode" << endl;
    if(argc == 1)
    {
        // Get the argument
        string argument = *argv;
        string objectName = argument.substr(0, argument.find('.'));
        string objectType = argument.substr(argument.find('.') + 1, argument.size());

        // Is it a game or a board
        if(objectType == "game")
            cout << "Please specify at least one board to create the game: " << objectName << endl;
        else if(objectType == "board")
            createBoard(objectName);
    }
    else if(argc > 1)
    {
        bool areAllBoards;
        // Get all the arguments
        vector<string> arguments;
        arguments.reserve(argc);
        for(int i = 0; i < argc; i++)
        {
            arguments.emplace_back(*argv);
        }

        // Are they all boards or not
        areAllBoards = all_of(arguments.begin(), arguments.end(), [](const string& arg){
            return (arg.substr(arg.find('.') + 1, arg.size()) == "board");
        });
        if(areAllBoards)
        {
            for(const string& board : arguments)
                createBoard(board.substr(0, board.find('.')));
            return true;
        }
        else
        {
            string argumentName = arguments[0].substr(0,arguments[0].find('.'));
            string argumentType = arguments[0].substr(arguments[0].find('.') + 1, arguments[0].size());
            if(argumentType == "game")
            {
                areAllBoards = all_of(arguments.begin() + 1, arguments.end(), [](const string& arg){
                    return (arg.substr(arg.find('.') + 1, arg.size()) == "board");
                });
                if(areAllBoards)
                {
                    /////////////// Create a game /////////////////////
                    // Starting to create the game
                    cout << "\t\tCreating Game: " << argumentName << endl;

                    // Creating game boards
                    arguments.erase(arguments.begin());
                    for(const string& board : arguments)
                        createBoard(board.substr(0, board.find('.')));
                }
            }
        }
    }
    return false;
}

// Play a game app
bool gamePlay(int argc, char** argv)
{
    // TODO: WRITE GAME PLAY
    return false;
}

int main(int argc, char** argv)
{
//    auto* board = new Board("Test", 20, 20);
//    auto* oueurj = new Oueurj(new Position(10,10), board);
//    board->addElement(oueurj);
//    for(vector<Element*> ligne : board->getBoardElements())
//        for(Element* element : ligne)
//            if((element->getPosition()->getX() == 0) || (element->getPosition()->getX() == 19) || (element->getPosition()->getY() == 0) || (element->getPosition()->getY() == 19))
//                board->addElement(new Reumu(element->getPosition(), board));
//    auto* teupor = new Teupor(new Position(5,0), board);
//    board->addElement(teupor);
//    board->addElement(new Diam(new Position(5,5), teupor, board));
//    board->addElement(new Geurchar(new Position(9,9), Teleportations::SmartTeleportation, board));
//    board->addElement(new Geurchar(new Position(14,9), Teleportations::RandomTeleportation, board));
//    board->addElement(new SStreumon(new Position(10,11), board));
//    board->addElement(new PStreumon(new Position(17,17), board));
//    board->addElement(new XStreumon(new Position(1,4), board));
//    board->addElement(new IStreumon(new Position(5,7),board));
//    board->displayBoard();
//    cout << board->boardPlay() << endl;
//    board->boardSave();

//    board = Board::boardLoad("Test");
//    board->boardPlay();

    string exeGamePlay = "./gp", exeGameCreate = "./gc";
    if(*argv == exeGamePlay)
        gamePlay(--argc,++argv);
    else if(*argv == exeGameCreate)
        gameCreate(--argc,++argv);
    gameCreate(--argc,++argv);
    return 0;
}
