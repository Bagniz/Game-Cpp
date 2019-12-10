//
// Created by netbook on 10/12/2019.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <string>
#include <vector>
#include <map>
#include "Board.h"

using namespace std;

class Game
{
private:
    string gameName, playerName, currentBoard;
    int gameScore;
    vector<Board> boards;
    vector<map<string,int>> topTenScores;
public:
    Game();
    Game(string name, vector<string> boards);
    void gamePlay();
    void gameOver();
    void gameSave();
};


#endif //GAME_GAME_H
