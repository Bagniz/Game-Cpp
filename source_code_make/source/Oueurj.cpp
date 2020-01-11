#include <algorithm>
#include <random>
#include <thread>
#include <sys/param.h>
#include <cstdio>
#include <termio.h>
#include <unistd.h>
#include "../header/Oueurj.h"

Oueurj::Oueurj() : Element()
{
    this->symbole = 'J';
}

Oueurj::Oueurj(Position* p, Board* b) : Element(p, b), teleportations()
{
    this->symbole = 'J';
}

void Oueurj::displayEmptyPositions(const vector<Element*>& emtyElements)
{
    cout << "Choose one of these teleporation positions:";
    for(Element* element : emtyElements)
        cout << "(" << element->getPosition()->getX() << "," << element->getPosition()->getY() << ")";
}

bool Oueurj::displayAvailableTeleportations() const
{
    // Show available teleportations
    cout << "Available telepotations: ";
    if(this->teleportations.empty())
    {
        cout << "there is no available teleportations, collect some." << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        return false;
    }
    else
    {
        long randomTeleportatioCount = count_if(teleportations.begin(), teleportations.end(), [](Teleportations teleportation){
            return teleportation == Teleportations::RandomTeleportation;
        });

        cout << endl;
        if(randomTeleportatioCount > 0)
            cout << "1.RandomTeleportation (" << randomTeleportatioCount << ")." << endl;

        long placeTeleportationCount = count_if(teleportations.begin(), teleportations.end(), [](Teleportations teleportation){
            return teleportation == Teleportations::PlaceTeleportation;
        });
        if(placeTeleportationCount > 0)
            cout << "2.PlaceTeleportation (" << placeTeleportationCount << ")." << endl;

        long axesTeleportationCount = count_if(teleportations.begin(), teleportations.end(), [](Teleportations teleportation){
            return teleportation == Teleportations::AxesTeleportation;
        });
        if(axesTeleportationCount > 0)
            cout << "3.AxesTeleportation (" << axesTeleportationCount << ")." << endl;

        long smartTeleportationTeleportation = count_if(teleportations.begin(), teleportations.end(), [](Teleportations teleportation){
            return teleportation == Teleportations::SmartTeleportation;
        });
        if(smartTeleportationTeleportation > 0)
            cout << "4.SmartTeleportation (" << smartTeleportationTeleportation << ")." << endl;

        return true;
    }
}

bool Oueurj::hasTeleportation(Teleportations teleportation) {
    for(Teleportations t : this->teleportations)
        if(t == teleportation)
            return true;
    return false;
}

void Oueurj::teleport()
{
    if(this->displayAvailableTeleportations())
    {
        int x, y;
        vector<Element*> emptyElements;
        bool wantToTeleport = true;
        long chosenTeleportation;

        while(wantToTeleport)
        {
            cout << "Enter teleportation number or 0 to cancel teleportation : ";
            cin >> chosenTeleportation;

            switch (chosenTeleportation)
            {
                // Cancel Teleportation
                case 0:
                {
                    wantToTeleport = false;
                    continue;
                }
                // Random Teleportaions
                case 1:
                {
                    if(this->hasTeleportation(Teleportations::RandomTeleportation))
                    {
                        // Get the empty elements
                        for(vector<Element*> ligneElements : this->board->getBoardElements())
                            copy_if(ligneElements.begin(), ligneElements.end(), back_inserter(emptyElements), [](Element* element){
                                return element->getSymbole() == ' ';
                            });

                        // Generate a random number for teleporation destination
                        random_device randomDevice;
                        uniform_int_distribution<int> uniformIntDistribution(0, emptyElements.size() - 1);
                        Position* teleportPosition = emptyElements[uniformIntDistribution(randomDevice)]->getPosition();

                        // Teleport to the new position
                        this->board->moveElement(this->getPosition(), teleportPosition);

                        // Delete teleportation from the player
                        for(unsigned i = 0; i < this->teleportations.size(); ++i)
                            if(this->teleportations[i] == Teleportations::RandomTeleportation)
                            {
                                this->teleportations.erase(this->teleportations.begin() + i);
                                break;
                            }
                        wantToTeleport = false;
                    }
                    continue;
                }
                // Places Teleportation
                case 2:
                {
                    if(this->hasTeleportation(Teleportations::PlaceTeleportation))
                    {
                        // Get the empty elements hoizontaly
                        for(Element* element: this->board->getBoardElements()[this->getPosition()->getX()]){
                            if(element->getSymbole() == ' ')
                                emptyElements.emplace_back(element);
                        }
                        // Get the empty elements verticly
                        for(unsigned i = 1; i < (this->board->getBoardElements().size() - 1); i++){
                            if(this->board->getBoardElements()[i][this->getPosition()->getY()]->getSymbole() == ' ')
                                emptyElements.emplace_back(this->board->getBoardElements()[i][this->getPosition()->getY()]);
                        }

                        // Delete teleportation from the player
                        for(unsigned i = 0; i < this->teleportations.size(); ++i)
                            if(this->teleportations[i] == Teleportations::PlaceTeleportation)
                            {
                                this->teleportations.erase(this->teleportations.begin() + i);
                                break;
                            };
                        wantToTeleport = false;
                        break;
                    }
                    else
                        continue;
                }
                // Axes Teleportation
                case 3:
                {
                    if(this->hasTeleportation(Teleportations::AxesTeleportation))
                    {
                        // Get the empty elements of the diagonal
                        int boardWidth = this->board->getBoardElements()[0].size(), boardHeight = this->board->getBoardElements().size();
                        int pivot = (this->getPosition()->getX() < this->getPosition()->getY())? this->getPosition()->getX() : this->getPosition()->getY(); 
                        int startingXPosition = this->getPosition()->getX() - pivot, startingYPosition = this->getPosition()->getY() - pivot;
                        for(int i = startingXPosition + 1, j = startingYPosition + 1; i < (boardHeight - 1) && j < (boardWidth - 1); i++,j++){
                            if(this->board->getBoardElements()[i][j]->getSymbole() == ' ')
                                emptyElements.emplace_back(this->board->getBoardElements()[i][j]);
                        }

                        // Get the empty elements of the antidiagonal
                        int yDiffrence = boardWidth - this->getPosition()->getY();
                        pivot = (this->getPosition()->getX() < yDiffrence)? this->getPosition()->getX() : yDiffrence;
                        startingXPosition = this->getPosition()->getX() - pivot, startingYPosition = this->getPosition()->getY() + pivot;
                        for(int i = startingXPosition + 1, j = startingYPosition - 1; i < (boardHeight - 1) && j > 0; i++,j--){
                            if(this->board->getBoardElements()[i][j]->getSymbole() == ' ')
                                emptyElements.emplace_back(this->board->getBoardElements()[i][j]);
                        }

                        // Delete teleportation from the player
                        for(unsigned i = 0; i < this->teleportations.size(); ++i)
                            if(this->teleportations[i] == Teleportations::AxesTeleportation)
                            {
                                this->teleportations.erase(this->teleportations.begin() + i);
                                break;
                            }
                        wantToTeleport = false;
                        break;
                    }
                    else
                        continue;
                }
                // Smart Teleportation
                case 4:
                {
                    if(this->hasTeleportation(Teleportations::SmartTeleportation))
                    {
                        // Get the empty elements
                        for(vector<Element*> ligneElements : this->board->getBoardElements())
                            copy_if(ligneElements.begin(), ligneElements.end(), back_inserter(emptyElements), [](Element* element){
                                return element->getSymbole() == ' ';
                            });

                        // Delete teleportation from the player
                        for(unsigned i = 0; i < this->teleportations.size(); ++i)
                            if(this->teleportations[i] == Teleportations::SmartTeleportation)
                            {
                                this->teleportations.erase(this->teleportations.begin() + i);
                                break;
                            }
                        wantToTeleport = false;
                        break;
                    }
                    else
                        continue;
                }
                // Choose Again
                default:
                {
                    continue;
                }
            }

            // Show the empty elements positions
            if(emptyElements.empty())
            {
                cout << "There is no empty positions" << endl;
                break;
            }

            // Choose the empty position
            do{
                cout << "Please enter the X and the Y of the empty position :" << endl;
                cout << "X:";
                cin >> x;
                cout << "Y:";
                cin >> y;
            } while (all_of(emptyElements.begin(), emptyElements.end(), [x, y](Element* element){
                return ((element->getPosition()->getX() != x) || (element->getPosition()->getY() != y));
            }));

            // Teleport to the chosen position
            this->board->moveElement(this->getPosition(), new Position(x, y));

            // Display the board
            this->board->displayBoard();
        }
    }
}

bool Oueurj::onCollision(Element* element)
{
    if(element->getSymbole() == 'M' || element->getSymbole() == 'P' || element->getSymbole() == 'X' || element->getSymbole() == 'I')
        this->board->setBoardState(-2);
    return false;
}

void Oueurj::move()
{
    // Detect the click char
    int clickedButton;
    Position* newPosition;

    clickedButton = int(clickedChar());
    switch (clickedButton)
    {
        // Case move up left 'a' || 'A'
        case 97:
        case 65:
        {
            newPosition = new Position(this->getPosition()->getX() - 1, this->getPosition()->getY() - 1);
            break;
        }

        // Case move up 'z' || 'Z'
        case 122:
        case 90:
        {
            newPosition = new Position(this->getPosition()->getX() - 1, this->getPosition()->getY());
            break;
        }

        // Case move up right 'e' || 'E'
        case 101:
        case 69:
        {
            newPosition = new Position(this->getPosition()->getX() - 1, this->getPosition()->getY() + 1);
            break;
        }

        // Case move left 'q' || 'Q'
        case 113:
        case 81:
        {
            newPosition = new Position(this->getPosition()->getX(), this->getPosition()->getY() - 1);
            break;
        }

        // Case move down 's' || 'S'
        case 115:
        case 83:
        {
            newPosition = new Position(this->getPosition()->getX() + 1, this->getPosition()->getY());
            break;
        }

        // Case move right 'd' || 'D'
        case 100:
        case 68:
        {
            newPosition = new Position(this->getPosition()->getX(), this->getPosition()->getY() + 1);
            break;
        }

        // Case move down left 'w' || 'W'
        case 119:
        case 87:
        {
            newPosition = new Position(this->getPosition()->getX() + 1, this->getPosition()->getY() - 1);
            break;
        }

        // Case move down right 'c' || 'C'
        case 99:
        case 67:
        {
            newPosition = new Position(this->getPosition()->getX() + 1, this->getPosition()->getY() + 1);
            break;
        }

        // Case Teleport 't' || 'T'
        case 116:
        case 84:
        {
            this->teleport();
            return;
        }

        // Case exit game 'delete'
        case 127:
        {
            this->board->setBoardState(-1);
            return;
        }

        // Default case
        default:
        {
            return;
        }
    }

    // Check if it can move to the desired
    // position and move to it
    if(this->board->getElement(newPosition)->onCollision(this))
    {
        // Move
        this->board->moveElement(this->getPosition(), newPosition);
        board->setPlayerXPosition(this->getPosition()->getX());
        board->setPlayerYPosition(this->getPosition()->getY());

        // Add score
        Score newScore{this->board->getPlayerScore().playerName, this->board->getPlayerScore().playerScore + 1};
        this->board->setBoardScore(newScore);
    }
}

char Oueurj::clickedChar()
{
    struct termios oldSettings, newSettings;
    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );
    fd_set set;
    FD_ZERO( &set );
    FD_SET( fileno( stdin ), &set );
    int res = select( fileno( stdin )+1, &set, nullptr, nullptr, nullptr);
    if( res > 0 )
    {
        char c;
        read( fileno( stdin ), &c, 1);
        tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
        return c; // Return the clicked char
    }
    else if( res < 0 )
    {
        perror( "select error" );
    }
    else
    {
        printf( "Select timeout\n" );
    }
    tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
    return '\0';
}
