#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <iostream>
#include <vector>
#include "Score.h"
#include "Position.h"

using namespace std;

class Element;

class Board {
private:
    int boardState, playerXPosition, playerYPosition;
    string boardName;
    Score playerScore;
    vector<vector<Element*>> boardElements;
    vector<Element*> movingElements;

public:
    Board();
    Board(string boardName, const int width, const int height);
    void deleteSaveBoardFiles(string playerName);
    int boardPlay();
    void boardSave(bool saveToNew);
    void boardOver();
    static Board* boardLoad(const string& name);
    bool addElement(Element* element);
    bool removeElement(Element* element);
    void moveElement(Position* oldPosition, Position* newPosition);
    void displayBoard() const;
    Element* getElement(const Position* position);
    int getBoardState();
    void setBoardState(int state);
    string getBoardName() const;
    Score getPlayerScore() const;
    void setBoardScore(Score& score);
    void setPlayerXPosition(int x);
    void setPlayerYPosition(int y);
    vector<vector<Element*>> getBoardElements();
    ~Board();
};

#endif //GAME_BOARD_H
