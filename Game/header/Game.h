//
// Created by bagniz on 12/19/19.
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
    string gameName, currentBoard;
    Score playerScore;
    vector<Score*> playerTopTenScores;
    vector<Board*> gameBoards;

public:
    Game();
    Game(const string& gameName);
    void gamePlay();
    void gameOver();
    void gameSave();
    void displayGame() const;
    bool addBoard(Board* board);
    bool removeBoard(const string& boardName);
    bool saveNewTopScore(Score* score);
    ~Game();
};

#endif //GAME_GAME_H
