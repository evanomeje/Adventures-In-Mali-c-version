#include "MemoryGame.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>


// MusicDune class implementation
MusicDune::MusicDune() {
    instruments = { "Talking Drum", "Djembe", "Balafon", "Tamani", "Kora" };
    score = 0;
    gameOver = false;
    srand(time(nullptr));
}

void MusicDune::generateSequence() {
    std::random_shuffle(instruments.begin(), instruments.end());
    musicSequence.clear();
    positions.clear();

    std::vector<std::vector<std::string>> manualDirections = {
        {"left", "middle", "right"},
        {"right", "middle", "left"},
        {"middle", "left", "right"},
        {"left", "right", "middle"}
    };

    std::vector<std::string> directions = manualDirections[currentRound];

    for (int i = 0; i < 3 && i < instruments.size(); ++i) {
        musicSequence.push_back(instruments[i]);
        positions[instruments[i]] = directions[i];
    }
}

void MusicDune::showRoundQuest() {
    system("clear");

    for (size_t i = 0; i < musicSequence.size(); ++i) {
        std::string instrument = musicSequence[i];
        std::string position = positions[instrument];
        int numSpaces = 0;

        if (position == "left") {
            std::cout << "   ";
        } else if (position == "middle") {
            numSpaces = (80 - instrument.length()) / 2;
        } else if (position == "right") {
            numSpaces = 80 - instrument.length();
        }

        std::cout << std::string(numSpaces, ' ') << instrument << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system("clear");
    }
}

void MusicDune::playerInput() {
std::cin >> playerDirection;
}

bool MusicDune::checkAnswer() {
    for (const auto& instrument : musicSequence) {
        std::cout << "Type the direction (left, right, middle) where you heard the " << instrument << ": ";
        playerInput();
        std::string expectedDirection = positions[instrument];

        if (playerDirection != expectedDirection) {
            std::cout << "Incorrect." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(4));
            return false;
        }
    }

    std::cout << "Correct!" << std::endl;
    return true;
}

void MusicDune::play() {

     for (int round = 0; round < 4; ++round) {
        currentRound = round;
        generateSequence();
        showRoundQuest();

        if (checkAnswer()) {
            score++;
        }
    }

    //std::cout << "Final Score: " << score << std::endl;
}

// LostCarvan class implementation
LostCarvan::LostCarvan() {
    words = { "left", "right", "forward", "backward", "stop" };
    roundNumber = 1;
    gameOver = false;
    srand(time(NULL));
}

void LostCarvan::generateSequence() {
    QuestSequence.clear();
    std::vector<std::string> tempWords = words; 
    std::random_shuffle(tempWords.begin(), tempWords.end());
    
    int sequenceLength = roundNumber * 2;
    for (int i = 0; i < sequenceLength; i++) {
        QuestSequence.push_back(tempWords[i % tempWords.size()]);
    }
}


void LostCarvan::showRoundQuest() {
    std::cout << "Get ready to remember the directions..." << std::endl;


    std::this_thread::sleep_for(std::chrono::seconds(3)); 


    system("clear"); 


    std::cout << "Remember the following directions:" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (const std::string& direction : QuestSequence) {
        std::cout << direction << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(10)); 

    system("clear"); 

    std::cout << "Now, input the directions you remember:" << std::endl;
}

void LostCarvan::playerInput() {
    std::string input;
    playerAnswer.clear();
    for (int i = 0; i < QuestSequence.size(); i++) {
        std::cin >> input;
        playerAnswer.push_back(input);
    }
}

bool LostCarvan::checkAnswer() {
    int correctWords = 0;

    for (int i = 0; i < QuestSequence.size(); i++) {
        if (i < playerAnswer.size() && QuestSequence[i] == playerAnswer[i]) {
            correctWords++;
        }
    }

    score += correctWords * QuestSequence.size();
    std::cout << "You got " << correctWords << " directions correct!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    return correctWords == QuestSequence.size();
}

void LostCarvan::play() {
        while (!gameOver) {
        generateSequence();
        showRoundQuest();
        playerInput();
        if (!checkAnswer()) {
            gameOver = true;
        }
        roundNumber++;
    }
    //std::cout << "Game Over! Your final score is: " << score << std::endl;
}

