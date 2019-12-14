#include <iostream>
#include "headers/Board.h"
#include "headers/Reumu.h"

using namespace std;

bool gameCreate(char** argv)
{
    return false;
}

bool gameLoad(char** argv)
{
    return false;
}

int main(int argc, char** argv)
{
    int size=20;

    Board board("first_try",size);
    Position position(0,0);
    Reumu reumu(position, board);
    Element element(' ',position,board);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i==0 || j==0 || j==size-1 || i==size-1){
                position.setX(i);
                position.setY(j);
                reumu.setPosition(position);
                board.addElement(reumu);
            }else{
                position.setX(i);
                position.setY(j);
                element.setPosition(position);
                board.addElement(element);
            }
        }
    }
    board.displayBoard();
    board.boardSave();
    return 0;
}
