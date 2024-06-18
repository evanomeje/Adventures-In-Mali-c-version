#include <gtest/gtest.h>
#include "MemoryGame.h"

// Unit tests for MusicDune class
TEST(MusicDuneTest, GenerateSequenceTest) {
    MusicDune game;
    game.generateSequence();
    
    EXPECT_EQ(game.positions[game.musicSequence[0]], "left");

    EXPECT_EQ(game.musicSequence.size(), 3);

    for (const std::string& instrument : game.instruments) {
        EXPECT_TRUE(std::find(game.musicSequence.begin(), game.musicSequence.end(), instrument) != game.musicSequence.end());
    }
}

TEST(MusicDuneTest, CheckAnswerTest) {
    MusicDune game;

    game.generateSequence();
    game.playerDirection = "left";
    EXPECT_TRUE(game.checkAnswer());
}

TEST(LostCarvanTest, CheckAnswerTest) {
    LostCarvan game;
    
    game.generateSequence();
    game.playerAnswer = game.QuestSequence;
    EXPECT_TRUE(game.checkAnswer());
}
