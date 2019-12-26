//
// Created by bagniz on 12/19/19.
//

#include <algorithm>
#include <random>
#include <thread>
#include "Oueurj.h"
#include "clicked_char.h"

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
                        for(int i = 0; i < this->teleportations.size(); ++i)
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
                        // Get the empty elements
                        for(vector<Element*> ligneElements : this->board->getBoardElements())
                            copy_if(ligneElements.begin(), ligneElements.end(), back_inserter(emptyElements), [](Element* element){
                                return element->getSymbole() == ' ';
                            });

                        // Delete teleportation from the player
                        for(int i = 0; i < this->teleportations.size(); ++i)
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
                        // Get the empty elements
                        for(vector<Element*> ligneElements : this->board->getBoardElements())
                            copy_if(ligneElements.begin(), ligneElements.end(), back_inserter(emptyElements), [](Element* element){
                                return element->getSymbole() == ' ';
                            });

                        // Delete teleportation from the player
                        for(int i = 0; i < this->teleportations.size(); ++i)
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
                        for(int i = 0; i < this->teleportations.size(); ++i)
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
                cout << "There is no empty positions" << endl;
            else
                Oueurj::displayEmptyPositions(emptyElements);

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

void Oueurj::move()
{
    // Detect the click char
    int clickedButton;
    Position* newPosition;

    clickedButton = int(clickedChar());
    switch (clickedButton)
    {
        // Case move up 'a' || 'A'
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

        // Case move up 'e' || 'E'
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

        // Case move up 'w' || 'W'
        case 119:
        case 87:
        {
            newPosition = new Position(this->getPosition()->getX() + 1, this->getPosition()->getY() - 1);
            break;
        }

        // Case move up 'c' || 'C'
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
        this->board->moveElement(this->getPosition(), newPosition);
}