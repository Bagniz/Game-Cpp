//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include "Position.h"

using namespace std;
class Element {
private:
    char symbole;
    Position position;
public:
    Element();
    Element(Position position);
};


#endif //GAME_ELEMENT_H
