//
// Created by bagniz on 12/19/19.
//

#ifndef GAME_DIAM_H
#define GAME_DIAM_H

#include "Element.h"
#include "Teupor.h"

using namespace std;

class Diam : public Element
{
private:
    Teupor* teupor;

public:
    Diam();
    Diam(Position* p, Teupor* t, Board* b);
    bool onCollision(Element* element);
    Teupor* getTeupor() const;
    void setTeuport(Teupor* t);
};


#endif //GAME_DIAM_H
