#include <iostream>
#include "header/Board.h"
#include "header/Oueurj.h"
#include "header/Reumu.h"
#include "header/Teupor.h"
#include "header/Diam.h"
#include "header/Geurchar.h"
#include "header/SStreumon.h"
#include "header/PStreumon.h"
#include "header/XStreumon.h"

using namespace std;

// Create a game app
bool gameCreate(char** argv)
{
    // TODO: WRITE GAME CREATE
    return false;
}

// Play a game app
bool gamePlay(char** argv)
{
    // TODO: WRITE GAME PLAY
    return false;
}

int main()
{
    auto* board = new Board("Test", 20, 20);
    auto* oueurj = new Oueurj(new Position(10,10), board);
    board->addElement(oueurj);
    for(vector<Element*> ligne : board->getBoardElements())
        for(Element* element : ligne)
            if((element->getPosition()->getX() == 0) || (element->getPosition()->getX() == 19) || (element->getPosition()->getY() == 0) || (element->getPosition()->getY() == 19))
                board->addElement(new Reumu(element->getPosition(), board));
    auto* teupor = new Teupor(new Position(5,0), board);
    board->addElement(teupor);
    board->addElement(new Diam(new Position(5,5), teupor, board));
    board->addElement(new Geurchar(new Position(9,9), Teleportations::SmartTeleportation, board));
    board->addElement(new Geurchar(new Position(14,9), Teleportations::RandomTeleportation, board));
    board->addElement(new SStreumon(new Position(10,11), board));
    board->addElement(new PStreumon(new Position(17,17), board));
    board->addElement(new XStreumon(new Position(1,4), board));
    board->displayBoard();
    cout << board->boardPlay() << endl;

//    Board::boardLoad("/home/bagniz/dev/test");
    return 0;
}
