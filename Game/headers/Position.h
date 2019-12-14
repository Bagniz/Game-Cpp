//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_POSITION_H
#define GAME_POSITION_H


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
    friend bool operator==(const Position &p,const Position &p1);
    ~Position();
};


#endif //GAME_POSITION_H
