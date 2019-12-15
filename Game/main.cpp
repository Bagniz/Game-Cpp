#include <iostream>
#include <algorithm>
#include "headers/Board.h"
#include "headers/Reumu.h"
#include "headers/Oueurj.h"
#include "headers/Teupor.h"
#include "headers/Diam.h"
#include "headers/Teleportations.h"
#include "headers/Geurchar.h"
#include "headers/SStreumon.h"

using namespace std;

bool gameCreate(char** argv)
{
    return false;
}

bool gameLoad(char** argv)
{
    return false;
}

bool operator==(const Position &p, const Position &p1) {
    return p.x == p1.x && p.y == p1.y;
}

vector<Position> positions;
Position generatePosition(int size){
    Position position;
    do{
        int x=rand()%size;
        int y=rand()%size;
        if (x==0)x++;
        if (y==0)y++;
        position.setX(x);
        position.setY(y);
    }while (std::find(positions.begin(), positions.end(), position)!=positions.end());
    return position;
}

int main(int argc, char** argv)
{
    srand (time(NULL));

    const int size=20;

    Board board("first_try",size);

    Position position;

    Reumu reumu(position, board);
    Element element(' ',position,board);

    switch (rand()%2){
        case 0:
            position.setX(rand()%size);
            position.setY((rand()%2)*(size-1));
        case 1:
            position.setX((rand()%2)*(size-1));
            position.setY(rand()%size);
    }
    Teupor teupor(position,board);

    position=generatePosition(size);
    Oueurj oueurj(position,board);

    position=generatePosition(size);
    Diam diam(position,teupor,board);

    position=generatePosition(size);
    Geurchar geurchar(position,Teleportations::RandomTeleportation,board);

    position=generatePosition(size);
    SStreumon sStreumon(position,board);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (teupor.getPosition().getX()==i && teupor.getPosition().getY()==j){
                board.addElement(teupor);
            }else if (i==0 || j==0 || j==size-1 || i==size-1){
                position.setX(i);
                position.setY(j);
                reumu.setPosition(position);
                board.addElement(reumu);
            } else if (oueurj.getPosition().getX()==i && oueurj.getPosition().getY()==j){
                board.addElement(oueurj);
            } else if (diam.getPosition().getX()==i && diam.getPosition().getY()==j){
                board.addElement(diam);
            } else if (geurchar.getPosition().getX()==i && geurchar.getPosition().getY()==j){
                board.addElement(geurchar);
            } else if (sStreumon.getPosition().getX()==i && geurchar.getPosition().getY()==j){
                board.addElement(sStreumon);
            } else{
                position.setX(i);
                position.setY(j);
                element.setPosition(position);
                board.addElement(element);
            }
        }
    }
    board.boardPlay();
    //board.boardSave();
    return 0;
}
