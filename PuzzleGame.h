
#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

class PuzzleGame {
public:
    virtual ~PuzzleGame() {}
    virtual void displayIntro() = 0;
    virtual int playGame() = 0;
    virtual void initializeGame() = 0;
    
};

class MarketChallenge : public PuzzleGame {
private:
    std::vector<std::string> maskMaterials;
    std::vector<std::string> availableMaterials;

    void displayAvailableMaterials();
    void gatherMaterials(std::vector<std::string>& gatheredMaterials);

public:
    MarketChallenge();
    void initializeGame() override;
    void displayIntro() override;
    int playGame() override;
};

class ElementalEnigma : public PuzzleGame {
private:
    std::unordered_map<std::string, std::string> elementCombination;
    std::vector<std::string> createdElement;

    void printDecorations(const std::string& dash);
    void printCreatedElements();
    void combineElements();
    bool checkCombination(const std::string& combinationKey);
    void displayEnding();

public:
    ElementalEnigma();
    void initializeGame() override;
    void displayIntro()override;
    int playGame() override;
};

class NKO_Script : public PuzzleGame {
private:
    std::unordered_map<std::string, int> dictionary;
    std::vector<int> answer;
    std::vector<int> vector_input;
    int correct;
    int score;

    void getUserInput();
    void decodeThis();
    void checkAnswer();
    ///

public:
    NKO_Script();
    void initializeGame() override;
    void displayIntro()override;
    int playGame() override;

};

#endif // PUZZLEGAME_H