#include <iostream>
#include <algorithm>
#include <list>
#include "headers/Board.h"
#include "headers/Reumu.h"
#include "headers/Oueurj.h"
#include "headers/Teupor.h"
#include "headers/Diam.h"
#include "headers/Teleportations.h"
#include "headers/Geurchar.h"
#include "headers/SStreumon.h"
#include "headers/Position.h"


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

ostream &operator<<(ostream &flux, Position const &position) {
    flux<<"("<<position.getX()<<"."<<position.getY()<<")";
    return flux;
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

    std::list<Reumu> reumus;
    std::list<Element> espaces;

    Teupor teupor(Position(0,10),board);
    Oueurj oueurj(generatePosition(size),board);
    Diam diam(generatePosition(size),teupor,board);
    Geurchar geurchar(generatePosition(size),Teleportations::RandomTeleportation,board);
    SStreumon sStreumon(generatePosition(size),board);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (teupor.getPosition().getX()==i && teupor.getPosition().getY()==j){
                board.addElement(teupor);
            }else if (i==0 || j==0 || j==size-1 || i==size-1){
                reumus.emplace_back(Reumu(Position(i, j), board));
                board.addElement(reumus.back());
            } else if (oueurj.getPosition().getX()==i && oueurj.getPosition().getY()==j){
                board.addElement(oueurj);
            } else if (diam.getPosition().getX()==i && diam.getPosition().getY()==j){
                board.addElement(diam);
            } else if (geurchar.getPosition().getX()==i && geurchar.getPosition().getY()==j){
                board.addElement(geurchar);
            } else if (sStreumon.getPosition().getX()==i && sStreumon.getPosition().getY()==j){
                board.addElement(sStreumon);
            } else{
                espaces.emplace_back(Element(' ',Position(i,j),board));
                board.addElement(espaces.back());
            }
        }
    }
    board.boardPlay();
    //board.boardSave();
    return 0;
}
