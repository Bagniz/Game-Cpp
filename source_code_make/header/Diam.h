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
    Diam(Position* p, Board* b);
    Diam(Position* p, Teupor* t, Board* b);
    bool onCollision(Element* element);
    Teupor* getTeupor() const;
    void setTeuport(Teupor* t);
};

#endif //GAME_DIAM_H
