#ifndef GAME_OUEURJ_H
#define GAME_OUEURJ_H

#include "Element.h"
#include "Teleportations.h"
#include "MovingElement.h"

class Oueurj : public Element, MovingElement
{
    // Friend class
    friend class Geurchar;

private:
    vector<Teleportations> teleportations;
    static void displayEmptyPositions(const vector<Element*>& elements) ;
    bool displayAvailableTeleportations() const;
    bool hasTeleportation(Teleportations teleportation);
    static char clickedChar();

public:
    Oueurj();
    Oueurj(Position* p, Board* b);
    void teleport();
    bool onCollision(Element* element) override;
    void move() override;
};

#endif //GAME_OUEURJ_H
