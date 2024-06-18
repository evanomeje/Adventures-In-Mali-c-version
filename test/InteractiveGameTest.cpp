#include <gtest/gtest.h>
#include "InteractiveGame.h"

TEST_F(InteractiveGameTest, MazeGameTest) {
    EXPECT_EQ(mazeGame.getCoinsEaten(), 0);
    EXPECT_FALSE(mazeGame.isGameOver());

    // Test movement within maze
    mazeGame.movePlayer('W');
    EXPECT_EQ(mazeGame.getPlayerX(), 1);
    EXPECT_EQ(mazeGame.getPlayerY(), 1);

    // Test eating a coin
    mazeGame.movePlayer('D');
    mazeGame.movePlayer('D');
    EXPECT_EQ(mazeGame.getCoinsEaten(), 1);
}

// Test Snake game functions
TEST_F(InteractiveGameTest, SnakeGameTest) {
    // Test initialization
    EXPECT_EQ(snakeGame.getWordLength(), snakeGame.getGuessedWord().length());
    EXPECT_FALSE(snakeGame.isGameOver());

    char letter = snakeGame.getWord()[0]; // Guess the first letter of the word
    snakeGame.searchWord(letter);
    EXPECT_EQ(snakeGame.getGuessedWord()[0], letter);

    int initialSnakeSize = snakeGame.getSnakeSize();
    snakeGame.transformSnake(true);
    EXPECT_GT(snakeGame.getSnakeSize(), initialSnakeSize);
}
