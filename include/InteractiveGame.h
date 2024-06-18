#ifndef INTERACTIVE_GAME_H
#define INTERACTIVE_GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <utility> 
#include <string> 

class InteractiveGame {
public:
    virtual void drawGame() = 0;
    virtual void playGame() = 0;
    virtual void displayGameOver() = 0;
    virtual bool isGameOver() = 0;
};

class Maze : public InteractiveGame {
private:
    std::vector<std::vector<char>> maze;
    int posX;
    int posY;
    int coinsEaten;
    std::vector<std::pair<int, int>> coinPositions;

public:
    Maze();

    void drawGame() override;
    void playGame() override;
    void displayGameOver() override;
    bool isGameOver() override;

private:
    void drawMaze();
    void movePlayer(char userInput);
    bool playerEatsCoin();
    void deleteCoin(int x, int y);
};

class Snake : public InteractiveGame {
private:
    std::vector<std::pair<int, int>> snake;
    std::vector<std::vector<char>> snakeBoard;
    std::vector<std::vector<char>> letters;
    std::unordered_map<std::string, std::string> LIST;
    std::string word;
    std::string guessedWord;

public:
    Snake();

    void drawGame() override;
    void playGame() override;
    void displayGameOver() override;
    bool isGameOver() override;

private:
    void drawSnakeGame();
    bool searchWord(char userInput);
    void transformSnake(bool found);
    void context();
};

#endif 
