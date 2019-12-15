//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_OUEURJ_H
#define GAME_OUEURJ_H

#include "Teleportations.h"
#include "MovingElement.h"
#include "Element.h"
#include "Board.h"

class Oueurj : public Element, MovingElement
{
    // Friend class
    friend class Geurchar;

private:
    vector<Teleportations> teleportations;

public:
    Oueurj();
    Oueurj(Position p, Board &b);
    void teleport();
    void move();
    ~Oueurj();
};


#endif //GAME_OUEURJ_H
