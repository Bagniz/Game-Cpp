//
// Created by bagniz on 12/19/19.
//

#include <random>
#include "../header/SStreumon.h"

SStreumon::SStreumon() : Element()
{
    this->symbole = 'S';
}

SStreumon::SStreumon(Position *p, Board *b) : Element(p, b)
{
    this->symbole = 'S';
}

bool SStreumon::onCollision(Element *element)
{
    if(element->getSymbole() == 'J')
    {
        board->setBoardStat(-2);
        return false;
    }
    return true;
}

void SStreumon::move()
{
    // Generate a random number between 1 and 8
    random_device randomDevice;
    uniform_int_distribution<int> uniformIntDistribution(1,8);
    int moveToCase = uniformIntDistribution(randomDevice);

    // Create a new Position
    Position* newPosition;

    // Which case to move to
    switch(moveToCase)
    {
        case 1:
        {
            newPosition = new Position(this->position->getX() - 1, this->position->getY() - 1);
            break;
        }
        case 2:
        {
            newPosition = new Position(this->position->getX(), this->position->getY() - 1);
            break;
        }
        case 3:
        {
            newPosition = new Position(this->position->getX() + 1, this->position->getY() - 1);
            break;
        }
        case 4:
        {
            newPosition = new Position(this->position->getX() - 1, this->position->getY());
            break;
        }
        case 5:
        {
            newPosition = new Position(this->position->getX() + 1, this->position->getY());
            break;
        }
        case 6:
        {
            newPosition = new Position(this->position->getX() - 1, this->position->getY() + 1);
            break;
        }
        case 7:
        {
            newPosition = new Position(this->position->getX(), this->position->getY() - 1);
            break;
        }
        case 8:
        {
            newPosition = new Position(this->position->getX() + 1, this->position->getY() + 1);
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
