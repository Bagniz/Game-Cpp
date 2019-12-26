//
// Created by bagniz on 12/19/19.
//

#include <fstream>
#include "Game.h"

Game::Game() : gameName(""), gameState(0),currentBoard(nullptr), playerScore() {}

Game::Game(const string& gameName) : Game()
{
    this->gameName = gameName;
}

void Game::gamePlay()
{
    // Variables
    int playedBoardStatus = 0;

    // Get the next board
    if(this->currentBoard == nullptr)
        if(!this->goToNextBoard(""))
        {
            this->gameState = -3;
            return;
        }

    do
    {
        // Set the player and score
        Score score{this->playerScore.playerName, 0};
        this->currentBoard->setBoardScore(score);

        // Play the current board
        playedBoardStatus = currentBoard->boardPlay();

        // Test board status
        if(playedBoardStatus == 1) // Won the board, Go to next if exists
        {
            this->playerScore.playerScore += this->currentBoard->getPlayerScore().playerScore;
            if(!this->goToNextBoard(this->currentBoard->getBoardName()))
            {
                if(!this->saveNewTopScore(this->playerScore))
                    this->gameState = playedBoardStatus; // Normal win
                else
                    this->gameState = 2; // Win with new high score
                this->gameSave(false);
            }
        }
        else
        {
            this->gameState = playedBoardStatus;
        }
    }while(this->gameState == 0);
}

void Game::gameOver()
{
    // Clear the terminal
    system("clear");

    // Print messages depending on the game status
    switch (this->gameState)
    {
        case 2:
        {
            cout << "\tCongratulations you won the game with new high score" << endl;
            cout << "Player : " <<  this->playerScore.playerName << "\tScore : " << this->playerScore.playerScore << endl;
            break;
        }

        case 1:
        {
            cout << "\tCongratulations you won the game with new high score" << endl;
            break;
        }

        case -1:
        {
            char response;
            cout << "\nSorry to see you leave" << endl;
            cout << "Do you want to save the game for other time ?(Y/N)";
            cin >> response;
            if(response == 'Y')
            {
                this->gameSave(true);
                cout << "The game is saved" << endl;
            }
            else
                cout << "The game did not save." << endl;
        }

        case -2:
        {
            cout << "\nYou lost!!!!" << endl;
        }

        case -3:
        {
            cout << "\nThis game does not containe any board!!" << endl;
        }
        default:
            throw bad_exception();
    }
}

Game *Game::gameLoad(const string& name)
{
    Game* game = nullptr;
    // Open game file
    ifstream gameFile(name + ".game");

    if(gameFile.is_open())
    {
        string word, key, value;
        Score score;
        int counter = 1;
        game = new Game();

        // Get the game information
        while(counter < 5 && getline(gameFile, word, '\n'))
        {
            // Get the key and the value of the line
            key = word.substr(0, word.find(':'));
            value = word.substr(word.find(':') + 1, word.size());

            // Get the value depending of the key
            if(key == "name")
                game->setGameName(value);
            else if(key == "currentBoard")
                game->setCurrentBoard(Board::boardLoad(value));
            else if(key == "player")
                score.playerName = value;
            else if(key == "score")
            {
                score.playerScore = stoi(value);
                game->setPlayerScore(score);
            }
            counter++;
        }

        // Get topTenScores
        while(getline(gameFile, word, '\n'))
        {
            // Get the key and the value of the line
            key = word.substr(0, word.find(':'));
            value = word.substr(word.find(':') + 1, word.size());

            // Get the value depending of the key
            if(key == "player")
                score.playerName = value;
            else if(key == "score")
            {
                score.playerScore = stoi(value);
                game->saveNewTopScore(Score{score.playerName, score.playerScore});
            }
            else if(key == "board")
                game->addBoard(Board::boardLoad(value));
        }
    }
    return game;
}

void Game::gameSave(bool saveBoards)
{
    // Open the game file
    ofstream gameFile(this->gameName + ".game");

    // Save game info
    gameFile << "name:" << this->gameName << endl;
    gameFile << "currentBoard:" << this->currentBoard << endl;
    gameFile << "player:" << this->playerScore.playerName << endl;
    gameFile << "score:" << this->playerScore.playerScore << endl;

    // Save the topTenScores
    for(const Score& score : this->playerTopTenScores)
    {
        gameFile << "player:" << score.playerName << endl;
        gameFile << "score:" << score.playerScore << endl;
    }

    // Save the boards
    if(saveBoards)
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
        for(const Score& score : this->playerTopTenScores)
        {
            cout << "\t" << playerPosition << ".Player name : " << score.playerName << ", with a score of : " << score.playerScore << endl;
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

bool Game::saveNewTopScore(const Score& score)
{
    // Insert the score if possible
    for(auto iterator = this->playerTopTenScores.begin(); iterator != this->playerTopTenScores.end(); iterator++)
    {
        if(iterator.operator*().playerScore < score.playerScore)
        {
            this->playerTopTenScores.emplace(iterator, score);
            return true;
        }
    }
    if(this->playerTopTenScores.size() < 10)
        this->playerTopTenScores.emplace_back(score);
    return false;
}

string Game::getGameName() const
{
    return this->gameName;
}

Score Game::getPlayerScore() const
{
    return this->playerScore;
}

Board *Game::getCurrentBoard() const
{
    return this->currentBoard;
}

bool Game::goToNextBoard(const string& currentBoardName)
{
    if(currentBoardName.empty())
    {
        this->currentBoard = this->gameBoards.begin().operator*();
        return true;
    }
    else
    {
        for(auto iterator = this->gameBoards.begin(); iterator != this->gameBoards.end(); ++iterator)
        {
            if(iterator.operator*()->getBoardName() == currentBoardName)
            {
                if(++iterator != this->gameBoards.end())
                {
                    this->currentBoard = iterator.operator*();
                    return true;
                }
            }
        }
    }
    return false;
}

void Game::setGameName(const string &name)
{
    this->gameName = name;
}

void Game::setPlayerScore(Score& score)
{
    this->playerScore = score;
}

void Game::setCurrentBoard(Board *board)
{
    this->currentBoard = board;
}

Game::~Game() {
    for(Board* board: gameBoards)
        delete board;
}
