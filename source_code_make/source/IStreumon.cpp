#include <random>
#include "../header/IStreumon.h"

IStreumon::IStreumon() : Element()
{
    this->symbole = 'I';
}

IStreumon::IStreumon(Position *p, Board *b) : Element(p, b)
{
    this->symbole = 'I';
}

bool IStreumon::onCollision(Element *element)
{
    if(element->getSymbole() == 'J')
        board->setBoardState(-2);
    return false;
}

// Intelligent Monster Movement
void IStreumon::move()
{
    // Variables
    int xDirection = 0, yDirection = 0;
    int xMove, yMove;

    for(const vector<Element*>& ligneElements : this->board->getBoardElements()){
        for(Element* element : ligneElements){
            if(element->getSymbole()=='J'){
                if(element->getPosition()->getX() < this->getPosition()->getX())
                    xDirection=-1;
                else
                    xDirection=1;
                
                if(element->getPosition()->getY() < this->getPosition()->getY())
                    yDirection=-1;
                else
                    yDirection=1; 
                
                break;
            }
        }

        if(xDirection!=0 && yDirection!=0)
            break;
    }

    // Generate a random number that is 0 or 1
    random_device randomDevice;
    uniform_int_distribution<int> uniformIntDistribution(0,1);

    // Apply the generated number
    xMove = xDirection * uniformIntDistribution(randomDevice);
    yMove = yDirection * uniformIntDistribution(randomDevice);

    // Create the new moving position
    auto* newPosition = new Position(this->position->getX()+xMove,this->position->getY()+yMove);

    // Move if you can
    if(this->board->getElement(newPosition)->onCollision(this)){
        this->board->moveElement(this->getPosition(),newPosition);
    }
}
