#include "../header/Geurchar.h"
#include "../header/Oueurj.h"

Geurchar::Geurchar() : teleportation(Teleportations::RandomTeleportation), Element()
{
    this->symbole = '*';
}

Geurchar::Geurchar(Position* p, Teleportations t, Board* b) : teleportation(t), Element(p,b)
{
    this->symbole = '*';
}

bool Geurchar::onCollision(Element *element) {
    // Get the symbole of the element
    char elementSymbole = element->getSymbole();

    // Test if the element is an Oueurj
    if(elementSymbole == 'J')
    {
        // add a teleporation to the player
        auto* oueurj = dynamic_cast<Oueurj*>(element);
        oueurj->teleportations.emplace_back(this->teleportation);

        // remove the element from the board
        this->board->removeElement(this);

        return true;
    }
    return false;
}

Teleportations Geurchar::getTeleportation() const
{
    return this->teleportation;
}
