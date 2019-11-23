#ifndef GAME // If the class Game is not defined
#define GAME // the define the class Game as follows

#include <string>
#include <vector>
#include <map>

class Board;

class Game
{
    private:
        std::string gameName;
        int gameScore;
        std::vector<std::map<std::string, int>> topTenScores;
        std::vector<Board> boards;

    public:
        Game(std::string name, int score = 0);
        Game(std::string name, int score, std::vector<std::map<std::string, int>> &topTenScores);
        Game(std::string name, int score, std::vector<std::map<std::string, int>> &topTenScores, std::vector<Board> boards);
        bool addBoard(std::string name);
        bool removeBoard(std::string name);
};

#endif // End if
