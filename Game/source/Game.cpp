//
// Created by bagniz on 12/19/19.
//

#include <fstream>
#include "../header/Game.h"

Game::Game() : gameName(""), currentBoard(""), playerScore() {}

Game::Game(const string& gameName) : Game()
{
    this->gameName = gameName;
}

void Game::gamePlay()
{
    // TODO: CONTINUE GAME PLAY
}

void Game::gameOver()
{
    // TODO: CONTINUE GAME OVER
}

Game* gameLoad(string name)
{
    // TODO : WRITE GAME LOAD
    return nullptr;
}

void Game::gameSave()
{
    // Open the game file
    ofstream gameFile(this->gameName + ".game");

    // Save game info
    gameFile << "name:" << this->gameName << endl;
    gameFile << "currentBoard:" << this->currentBoard << endl;
    gameFile << "player:" << this->playerScore.playerName << ",score:" << this->playerScore.playerScore << endl;

    // Save the topTenScores
    for(Score* score : this->playerTopTenScores)
        gameFile << "player:" << score->playerName << ",score:" << score->playerScore << endl;

    // Save the boards
    for(Board* board : this->gameBoards)
    {
        gameFile << "board:" << board->getBoardName() << endl;
        board->boardSave();
    }

    gameFile.close();
}

void Game::displayGame() const
{
    // System command to clean terminal
    system("clear");

    // Display game name
    cout << "Game Name: " << this->gameName << endl;

    // Display game top ten scores
    cout << "Top Ten Scores in this games: ";
    if(this->playerTopTenScores.empty())
        cout << "There is no scores yet." << endl;
    else
    {
        int playerPosition = 0;
        cout << endl;
        for(Score* score : this->playerTopTenScores)
        {
            cout << "\t" << playerPosition << ".Player name : " << score->playerName << ", with a score of : " << score->playerScore << endl;
            playerPosition++;
        }
    }

    // Display Game Boards
    cout << "Boards to play in this game: ";
    if(this->gameBoards.empty())
        cout << "There is no boards yet." << endl;
    else
    {
        for(Board* board : gameBoards)
            cout << "\tBoard: " << board->getBoardName() << endl;
    }
}

bool Game::addBoard(Board* board)
{
    // Check if the board does not already exists in the game
    for(Board* gameBoard : gameBoards)
    {
        if(gameBoard->getBoardName() == board->getBoardName())
            return false;
    }

    // Add the board to the game
    this->gameBoards.emplace_back(board);
    return true;
}

bool Game::removeBoard(const string& boardName)
{
    // Remove the board if it exists
    for(auto iterator = this->gameBoards.begin(); iterator != this->gameBoards.end(); iterator++)
    {
        if(iterator.operator*()->getBoardName() == boardName)
        {
            // Free up space of the board
            delete iterator.operator*();

            // Delete the pointer from the game
            this->gameBoards.erase(iterator);
        }
    }
    return false;
}

bool Game::saveNewTopScore(Score* score)
{
    // Insert the score if possible
    for(auto iterator = this->playerTopTenScores.begin(); iterator != this->playerTopTenScores.end(); iterator++)
    {
        if(iterator.operator*()->playerScore < score->playerScore)
        {
            this->playerTopTenScores.emplace(iterator, score);
            return true;
        }
    }
    return false;
}

Game::~Game() {
    for(Board* board: gameBoards)
        delete board;
}
