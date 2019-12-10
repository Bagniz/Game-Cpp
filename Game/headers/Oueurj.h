//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_OUEURJ_H
#define GAME_OUEURJ_H

#include "Teleportations.h"
#include "MovingElement.h"
#include "Element.h"

class Oueurj : public Element, MovingElement
{
private:
    Teleportations teleportations;
public:
    Oueurj();
    Oueurj(Position position);
    void teleport();
    void move();

    // Friend class
    friend class Geurchar;
};


#endif //GAME_OUEURJ_H
