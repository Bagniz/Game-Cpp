//
// Created by bagniz on 12/19/19.
//

#ifndef GAME_POSITION_H
#define GAME_POSITION_H

#include <iostream>

using namespace std;

class Position
{
private:
    int x, y;

public:
    explicit Position(int x = 0, int y = 0);
    int getX() const;
    void setX(int px);
    int getY() const;
    void setY(int py);
    friend ostream &operator<<( ostream &flux, Position const&position);
    friend bool operator==(const Position &p,const Position &p1);
};


#endif //GAME_POSITION_H
