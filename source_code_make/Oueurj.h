//
// Created by bagniz on 12/19/19.
//

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

public:
    Oueurj();
    Oueurj(Position* p, Board* b);
    void teleport();
    void move();
};

#endif //GAME_OUEURJ_H
