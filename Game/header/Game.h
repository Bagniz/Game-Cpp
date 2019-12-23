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
    string gameName;
    Score playerScore;
    Board* currentBoard;
    vector<Score*> playerTopTenScores;
    vector<Board*> gameBoards;

public:
    Game();
    Game(const string& gameName);
    void gamePlay();
    void gameOver();
    void gameSave();
    static Game* gameLoad(const string& name);
    void displayGame() const;
    bool addBoard(Board* board);
    bool removeBoard(const string& boardName);
    bool saveNewTopScore(Score* score);
    string getGameName() const;
    Score getPlayerScore() const;
    Board* getCurrentBoard() const;
    void setGameName(const string& name);
    void setPlayerScore(Score& score);
    void setCurrentBoard(Board* board);
    ~Game();
};

#endif //GAME_GAME_H
