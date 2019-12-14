//
// Created by netbook on 10/12/2019.
//

#include "../headers/Geurchar.h"
#include "../headers/Oueurj.h"

// Constructor
Geurchar::Geurchar() : Element()
{
    this->teleportation = Teleportations::RandomTeleportation;
}

// Constructor with @params
Geurchar::Geurchar(Position &p, Teleportations t, Board *b) : Element('*',p,b)
{
    this->teleportation = t;
}

/*
 * Get the symbole of the element
 * Test if the element is an Oueurj
 * if TRUE
 * add a teleporation to the player
 * remove the element from the board
 * return true
 * Else
 * return false*/
bool Geurchar::onCollision(Element &element)
{
    // Get the symbole of the element
    char elementSymbole = element.getSymbole();

    // Test if the element is an Oueurj
    if(elementSymbole == 'j')
    {
        // add a teleporation to the player
        Oueurj oueurj = dynamic_cast<Oueurj&>(element);
        oueurj.teleportations.emplace_back(this->teleportation);

        // remove the element from the board
        this->board->removeElement(this);

    }
    return true;
}

Geurchar::~Geurchar() {

}
