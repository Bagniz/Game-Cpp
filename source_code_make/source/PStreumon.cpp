//
// Created by bagniz on 12/19/19.
//

#include <random>
#include "../header/PStreumon.h"

PStreumon::PStreumon() : Element()
{
    this->symbole = 'P';
}

PStreumon::PStreumon(Position *p, Board *b) : Element(p, b)
{
    this->symbole = 'P';
}

bool PStreumon::onCollision(Element *element)
{
    if(element->getSymbole() == 'J')
        board->setBoardState(-2);
    return false;
}

void PStreumon::move()
{
    // Generate a random number between 1 and 8
    random_device randomDevice;
    uniform_int_distribution<int> uniformIntDistribution(1,4);
    int moveToCase = uniformIntDistribution(randomDevice);

    // Create a new Position
    Position* newPosition;

    // Which case to move to
    switch(moveToCase)
    {
        case 1:
        {
            newPosition = new Position(this->position->getX(), this->position->getY() - 1);
            break;
        }
        case 2:
        {
            newPosition = new Position(this->position->getX() - 1, this->position->getY());
            break;
        }
        case 3:
        {
            newPosition = new Position(this->position->getX() + 1, this->position->getY());
            break;
        }
        case 4:
        {
            newPosition = new Position(this->position->getX(), this->position->getY() + 1);
            break;
        }
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
