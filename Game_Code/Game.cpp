#include "Game.hpp"
#include "Board.hpp"

Game::Game(std::string name, int score) : gameName(name), gameScore(score)
{}

Game::Game(std::string name, int score, std::vector<std::map<std::string, int>> &topTenScores) : Game(name,score)
{
    this->topTenScores = topTenScores;
}


