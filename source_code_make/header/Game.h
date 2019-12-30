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
    int gameState;
    Score playerScore;
    Board* currentBoard;
    vector<Score> playerTopTenScores;
    vector<Board*> gameBoards;

public:
    Game();
    Game(const string& gameName);
    void gamePlay();
    void deleteSaveGameFiles(string playerName);
    void gameOver();
    void gameSave(bool saveBoards);
    static Game* gameLoad(const string& name);
    void displayGame() const;
    bool addBoard(Board* board);
    bool removeBoard(const string& boardName);
    bool saveNewTopScore(const Score& score);
    string getGameName() const;
    Score getPlayerScore() const;
    Board* getCurrentBoard() const;
    bool goToNextBoard(const string& currentBoardName);
    void setGameName(const string& name);
    void setPlayerScore(Score& score);
    void setCurrentBoard(Board* board);
    vector<Board*> getGameBoards();
    ~Game();
};

#endif //GAME_GAME_H
