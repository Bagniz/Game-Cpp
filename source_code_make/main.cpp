#include <iostream>
#include <algorithm>
#include "header/Board.h"
#include "header/Oueurj.h"
#include "header/Reumu.h"
#include "header/Teupor.h"
#include "header/Diam.h"
#include "header/Geurchar.h"
#include "header/SStreumon.h"
#include "header/PStreumon.h"
#include "header/XStreumon.h"
#include "header/IStreumon.h"
#include "header/Game.h"

using namespace std;

// Check if an other object already exists in the position
bool isPositionEmpty(Position* position, Board* board)
{
    if(board->getElement(position)->getSymbole() != ' ')
    {
        char response;
        cout << "An element already exists in the indicated position" << endl;
        cout << "Would you like to continue ?(Y/N)";
        cin >> response;

        if(response != 'Y')
            return false;
    }
    return true;
}

// Create a board
Board* createBoard(const string& boardName)
{
    /////////////// Create a board /////////////////////
    int boardWidth, boardHeight, elementChoice = 0, xPosition = 0, yPosition = 0;

    do
    {
        // Starting to create the board
        cout << "Creating board: " << boardName << endl;

        // Get board dimensions
        cout << "Please enter board width > 3:";
        cin >> boardWidth;
        cout << "Please enter board height > 3:";
        cin >> boardHeight;
    } while (boardWidth <= 3 || boardHeight <= 3);

    // Create the board
    auto* board = new Board(boardName, boardWidth, boardHeight);

    // Adding the walls
    for(const vector<Element*>& ligne : board->getBoardElements())
        for(Element* element : ligne)
            if((element->getPosition()->getX() == 0) || (element->getPosition()->getX() == boardHeight - 1) || (element->getPosition()->getY() == 0) || (element->getPosition()->getY() == boardWidth - 1))
                board->addElement(new Reumu(element->getPosition(), board));

    // Create board Elements
    do
    {
        // Choose which element to add
        cout << "Which element do you want to add" << endl;
        cout << "1. Reumu" << endl;
        cout << "2. Diam" << endl;
        cout << "3. Geurchar" << endl;
        cout << "4. SStreumon" << endl;
        cout << "5. XStreumon" << endl;
        cout << "6. PStreumon" << endl;
        cout << "7. IStreumon" << endl;
        cout << "0. Save" << endl;
        cout << "Element number: ";
        cin >> elementChoice;

        if(elementChoice == 0)
        {
            // Enter the players starting position
            do
            {
                cout << "Please enter the players starting position:" << endl;
                cout << "X:";
                cin >> xPosition;
                cout << "Y:";
                cin >> yPosition;
            }while(((xPosition <= 0) || (xPosition >= (boardHeight - 1))) || ((yPosition <= 0) || (yPosition >= (boardWidth - 1))));

            // Check if the position is empty
            Position* position = new Position(xPosition, yPosition);
            if(isPositionEmpty(position, board))
                board->addElement(new Oueurj(position, board));
            else
                elementChoice = -1;
        }
        else if(elementChoice < 7 && elementChoice > 0)
        {
            // Enter the elements position
            cout << "Please enter the elements position:" << endl;
            cout << "X:";
            cin >> xPosition;
            cout << "Y:";
            cin >> yPosition;

            while(((xPosition <= 0) || (xPosition >= (boardHeight - 1))) || ((yPosition <= 0) || (yPosition >= (boardWidth - 1))))
            {
                cout << "\t\tInvalid entered position" << endl;
                cout << "Please enter the elements position:" << endl;
                cout << "X:";
                cin >> xPosition;
                cout << "Y:";
                cin >> yPosition;
            }

            if(isPositionEmpty(new Position(xPosition, yPosition), board))
            {
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
                    while((txPosition != 0) && (txPosition != (boardHeight - 1)) && (tyPosition != 0) && (tyPosition != (boardWidth - 1)))
                    {
                        cout << "\t\tInvalid entered position" << endl;
                        cout << "Please enter the position of teupor associated with this diam:" << endl;
                        cout << "X:";
                        cin >> txPosition;
                        cout << "Y:";
                        cin >> tyPosition;
                    }

                    auto* tempTeupor = new Teupor(new Position(txPosition, tyPosition), board, false);
                    board->addElement(new Diam(new Position(xPosition, yPosition), tempTeupor, board));
                    board->addElement(tempTeupor);
                }
                else if(elementChoice == 3)
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
                else if(elementChoice == 4)
                    board->addElement(new SStreumon(new Position(xPosition, yPosition), board));
                else if(elementChoice == 5)
                    board->addElement(new XStreumon(new Position(xPosition, yPosition), board));
                else if(elementChoice == 6)
                    board->addElement(new PStreumon(new Position(xPosition, yPosition), board));
                else if(elementChoice == 7)
                    board->addElement(new IStreumon(new Position(xPosition, yPosition), board));
            }
        }
    }while(elementChoice != 0);
    board->boardSave();
    return board;
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
            argv++;
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
                    cout << "\tCreating Game: " << argumentName << endl;

                    // Creating the game
                    Game game(argumentName);

                    // Creating game boards
                    arguments.erase(arguments.begin());
                    for(const string& boardName : arguments)
                    {
                        Board* board = Board::boardLoad(boardName.substr(0, boardName.find('.')));
                        if(board == nullptr)
                            game.addBoard(createBoard(boardName.substr(0, boardName.find('.'))));
                        else
                            game.addBoard(board);
                        
                        if(boardName == *arguments.begin())
                            game.setCurrentBoard(board);
                    }
                    game.gameSave(true);
                    return true;
                }
            }
        }
    }
    return false;
}

// Play a game app
bool gamePlay(int argc, char** argv)
{
    if(argc == 1)
    {
        // Get argument name and type
        string arg = *argv;
        string argName = arg.substr(0, arg.find('.'));
        string argType = arg.substr(arg.find('.') + 1, arg.size());

        if(argType == "board")
        {
            // Get the board
            Board* board = Board::boardLoad(argName);

            if(board != nullptr)
            {
                // Get the players name
                Score player{"", 0};
                cout << "Please enter you name:";
                cin >> player.playerName;

                // Set the player and play the board
                if(player.playerName != board->getPlayerScore().playerName)
                    board->setBoardScore(player);
                board->boardPlay();

                // Board Over
                board->boardOver();
                return true;
            }
        }
        else if(argType == "game")
        {
            // Get the game
            Game* game = Game::gameLoad(argName);
            if(game != nullptr)
            {
                // Get the players name
                Score player{"", 0};
                cout << "Please enter you name:";
                cin >> player.playerName;

                // Set the player and play the game
                if(player.playerName != game->getPlayerScore().playerName)
                    game->setPlayerScore(player);
                game->gamePlay();

                // Game Over
                game->gameOver();
                return true;
            }
        }

        // If it not a board nor a game
        cout << "There is no game/board with this name" << endl;
    }
    else
        // If there is no arguments or more than one
        cout << "Wrong arguments" << endl;
    return false;
}

int main(int argc, char** argv)
{
    string exeGamePlay = "./gp", exeGameCreate = "./gc";
    if(*argv == exeGamePlay)
        gamePlay(--argc,++argv);
    else if(*argv == exeGameCreate)
        gameCreate(--argc,++argv);
    return 0;
}

// TODO: Save Board to player name