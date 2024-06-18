#include <gtest/gtest.h>
#include <iostream>
#include "PuzzleGame.h"

// Unit tests for MarketChallenge class
TEST(MarketChallengeTest, GatherMaterialsTest) {
    MarketChallenge game;
    std::vector<std::string> gatheredMaterials;
    std::vector<std::string> expectedMaterials = {"Wood", "Clay", "Beads", "Cowrie", "Knife", "Pigment"};
    game.gatherMaterials(gatheredMaterials);
    EXPECT_EQ(gatheredMaterials, expectedMaterials);
}

// Unit tests for ElementalEnigma class
TEST(ElementalEnigmaTest, InitializeGameTest) {
    ElementalEnigma game;
    game.initializeGame();
    std::vector<std::string> expectedElements = {"Earth", "Water", "Air", "Fire"};
    EXPECT_EQ(game.createdElement, expectedElements);
}

// Unit test for ElementalEnigma class
TEST(ElementalEnigmaTest, CombineElementsTest) {
    ElementalEnigma game;

    std::vector<std::string> correctCombination = {"Lava", "Water"};
    game.createdElement = correctCombination;
    game.combineElements();
    EXPECT_EQ(game.createdElement.back(), "obsidian");

    std::vector<std::vector<std::string>> incorrectCombinations = {
        {"Earth", "Fire"},
        {"Air", "Water"},
        {"Fire", "Air"}
    };
    for (const auto& incorrectCombination : incorrectCombinations) {
        game.createdElement = incorrectCombination;
        game.combineElements();
        EXPECT_NE(game.createdElement.back(), "obsidian");
    }

    std::vector<std::string> expectedCombination = {"Water", "Lava"};
    game.createdElement = expectedCombination;
    game.combineElements();
    EXPECT_EQ(game.createdElement.back(), "obsidian");

    expectedCombination = {"Lava", "Water"};
    game.createdElement = expectedCombination;
    game.combineElements();
    EXPECT_EQ(game.createdElement.back(), "obsidian");
}

// Unit tests for NKO_Script class
TEST(NKOScriptTest, CheckAnswerTest) {
    NKO_Script game;
    std::vector<int> userAnswers = {15, 7, 12, 16, 0, 96};
    game.vector_input = userAnswers;
    game.checkAnswer();
    EXPECT_EQ(game.score, 60);
}
