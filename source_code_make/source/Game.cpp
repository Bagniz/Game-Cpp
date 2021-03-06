#include <fstream>
#include "../header/Game.h"

Game::Game() : gameName(""), gameState(0), playerScore{"", 0}, currentBoard(nullptr) {}

Game::Game(const string& gameName) : Game()
{
    this->gameName = gameName;
}

// Play the game
void Game::gamePlay()
{
    // Variables
    int playedBoardStatus = 0;

    do{
        // Set the player and score
        Score score{this->playerScore.playerName, this->currentBoard->getPlayerScore().playerScore};
        this->currentBoard->setBoardScore(score);

        // Play the current board status
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

// Delete Game Save Files
void Game::deleteSaveGameFiles(string playerName){
    string fileName = "./Games/" + this->getGameName() + playerName + ".game";
    remove(fileName.c_str());

    for(Board* board : this->getGameBoards()){
        board->deleteSaveBoardFiles(playerName);
    }
}

// End the game sessions
void Game::gameOver()
{
    // Clear the terminal
    system("clear");

    // Print messages depending on the game status
    switch (this->gameState)
    {
        // Won the game with new score
        case 2:
        {
            cout << "\tCongratulations you won the game with new high score" << endl;
            cout << "Player : " <<  this->playerScore.playerName << "\t,Score : " << this->playerScore.playerScore << endl;
            this->deleteSaveGameFiles(this->getPlayerScore().playerName);
            break;
        }

        // Won the game
        case 1:
        {
            cout << "\tCongratulations you won the game" << endl;
            this->deleteSaveGameFiles(this->getPlayerScore().playerName);
            break;
        }

        // Exit the game
        case -1:
        {
            char response;
            cout << "\nSorry to see you leave" << endl;
            cout << "Do you want to save the game for other time ?(Y/N)";
            cin >> response;
            if(response  == 'Y' || response == 'y')
            {
                this->gameSave(true);
                cout << "The game is saved" << endl;
            }
            else
                cout << "The game did not save." << endl;
            break;
        }

        // Lost the game
        case -2:
        {
            cout << "\nYou lost!!!!" << endl;
            this->deleteSaveGameFiles(this->getPlayerScore().playerName);
            break;
        }

        default:
            throw bad_exception();
    }
}

// Load a game from a game file
Game *Game::gameLoad(const string& name)
{
    Game* game = nullptr;
    // Open game file
    ifstream gameFile("./Games/" + name + ".game");

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

// Save the game to a game file
void Game::gameSave(bool saveBoards)
{
    // Open the game file
    ofstream gameFile;
    if(saveBoards)
        gameFile.open("./Games/" + this->gameName + this->getPlayerScore().playerName + ".game");
    else
        gameFile.open("./Games/" + this->gameName + ".game");

    // Save game info
    gameFile << "name:" << this->gameName << endl;
    if(saveBoards)
    {
        gameFile << "currentBoard:" << this->getCurrentBoard()->getBoardName() + this->getPlayerScore().playerName << endl;
        gameFile << "player:" << this->getPlayerScore().playerName << endl;
        gameFile << "score:" << this->getPlayerScore().playerScore << endl;
    }
    else
    {
        gameFile << "currentBoard:" << (*this->gameBoards.begin())->getBoardName() << endl;
        gameFile << "player:" << "" << endl;
        gameFile << "score:" << 0 << endl;
    }

    // Save the topTenScores
    for(const Score& score : this->playerTopTenScores)
    {
        gameFile << "player:" << score.playerName << endl;
        gameFile << "score:" << score.playerScore << endl;
    }

    // Save the boards
    for(Board* board : this->gameBoards)
    {
        // Delete old file 
        if(!this->playerScore.playerName.empty()){
            string fileName = "./Boards/" + board->getBoardName() + this->getPlayerScore().playerName + ".board";
            remove(fileName.c_str());
        }
        
        // Create new one if necessary
        if(saveBoards && board->getBoardName() == currentBoard->getBoardName())
        {
            gameFile << "board:" << currentBoard->getBoardName() + this->getPlayerScore().playerName << endl;
            currentBoard->boardSave(true);
        }
        else
            gameFile << "board:" << board->getBoardName() << endl;
    }
    gameFile.close();
}

// Display all game info
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

// Add a board to the game
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

// Delete a board from the game
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

// Save a new top score in the game and only save top ten scores
bool Game::saveNewTopScore(const Score& score)
{
    // Insert the score if possible
    for(auto iterator = this->playerTopTenScores.begin(); iterator != this->playerTopTenScores.end(); iterator++)
    {
        if(iterator.operator*().playerScore < score.playerScore)
        {
            this->playerTopTenScores.emplace(iterator, score);
            if(this->playerTopTenScores.size() > 10)
                this->playerTopTenScores.erase(this->playerTopTenScores.end());
            return true;
        }
    }

    // Is the number of top scores lower than 10
    if(this->playerTopTenScores.size() < 10){
        this->playerTopTenScores.emplace_back(score);
        return true;
    }
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

// Got to the next board to play
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
                if((iterator + 1) != this->gameBoards.end())
                {
                    this->currentBoard = (iterator + 1).operator*();
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

vector<Score> Game::getPlayerTopTenScores(){
    return this->playerTopTenScores;
}

vector<Board*> Game::getGameBoards(){
    return this->gameBoards;
}

// Display game info
void Game::displayGameInfo(){
    system("clear");
    cout << "Welcome to " << this->getGameName() << " game !!" << endl;
    if(!this->getPlayerTopTenScores().empty()){
        cout << "Here are the top ten player scores:" << endl;
        for(Score playerScore : this->getPlayerTopTenScores()){
            cout << "Player: " << playerScore.playerName << ", Score: " << playerScore.playerScore << endl;
        }
    }
    else{
        cout << "There is no top scores in this game, Try to make the best score to beat!!" << endl;
    }
    cout << "Please click enter to start playing...";
    cin.get();
    cin.get();
}

Game::~Game() {
    for(Board* board: gameBoards)
        delete board;
}
