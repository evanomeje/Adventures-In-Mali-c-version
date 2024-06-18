
#include "PuzzleGame.h"

int PuzzleGame::playGame() {
    std::cout << "This is a generic puzzle game.\n";
    return 0;
}

// Implementation of MarketChallenge//
MarketChallenge::MarketChallenge() {
    initializeGame();
}

void MarketChallenge::initializeGame() {
    maskMaterials = {"Wood", "Clay", "Beads", "Cowrie", "Knife", "Pigment"};

    availableMaterials = {
        "Kente Fabric", "Hausa Leather Shoes", "Wooden Spoons",
        "Palm Oil", "Black Soap", "Cayenne Pepper",
        "Clay Pot", "Benin Bronze", "Elephant Tusk","Wood", "Clay", "Beads", "Cowrie", "Knife", "Pigment"
    };

    std::random_shuffle(availableMaterials.begin(), availableMaterials.end());
}

void MarketChallenge::displayIntro() {
    std::cout << "✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽\n";
    std::cout << "Gather materials to create your ceremonial mask.\n";
    displayAvailableMaterials();
        std::cout << "✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽\n";
        std::cout << "✽ Hint: Your beaded mask is shelled and carved, coloured with materials of the earth and sharpened by the desires of your mind ✽\n";
        std::cout << "✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽✽\n";
}

void MarketChallenge::displayAvailableMaterials() {
    std::cout << "Available Materials:\n";
    for (const auto& material : availableMaterials) {
        std::cout << "✣ " << material << std::endl;
    }
    std::cout << std::endl;
}

void MarketChallenge::gatherMaterials(std::vector<std::string>& gatheredMaterials) {
    int collectedCount = 0;

    while (collectedCount < maskMaterials.size()) {
        std::string input;

        std::cout << "What object do you need?" << std::endl;
        std::cin >> input;

        auto it = std::find(maskMaterials.begin(), maskMaterials.end(), input);
        bool isValidMaterial = (it != maskMaterials.end()); // Narrowed scope

        if (isValidMaterial) {
            if (std::find(gatheredMaterials.begin(), gatheredMaterials.end(), input) != gatheredMaterials.end()) {
                std::cout << "✣ You have already found " << input << ". Try another material." << std::endl;
            } else {
                std::cout << "✣ Correct! You found " << input << "  (" << ++collectedCount << "/" << maskMaterials.size() << ")" << std::endl;
                gatheredMaterials.push_back(input);
                availableMaterials.erase(std::remove(availableMaterials.begin(), availableMaterials.end(), input), availableMaterials.end());
            }
        } else {
            std::cout << "✣ Incorrect! That's not part of the mask." << std::endl;
            displayAvailableMaterials();
            std::cin.clear();
        }

        if (collectedCount == maskMaterials.size()) {
            break;
        }
    }
}


int  MarketChallenge::playGame() {
    displayIntro();
    std::vector<std::string> gatheredMaterials;
    gatherMaterials(gatheredMaterials);
    std::cout << "Congratulations! You have gathered all materials for your ceremonial mask.\n";
    return 50;
}

/******************************************************************************************************************************************************************/

// Implementation of ElementalEnigma
ElementalEnigma::ElementalEnigma() {
    initializeGame();
}

void ElementalEnigma::initializeGame() {
    elementCombination["EarthWater"] = "Mud";
    elementCombination["WaterEarth"] = "Mud";
    elementCombination["AirFire"] = "Smoke";
    elementCombination["FireAir"] = "Smoke";
    elementCombination["EarthAir"] = "Dust";
    elementCombination["AirEarth"] = "Dust";
    elementCombination["FireWater"] = "Steam";
    elementCombination["WaterFire"] = "Steam";
    elementCombination["EarthFire"] = "Lava";
    elementCombination["FireEarth"] = "Lava";
    elementCombination["LavaWater"] = "obsidian";
    elementCombination["WaterLava"] = "obsidian";
    elementCombination["LavaAir"] = "stone";
    elementCombination["AirLava"] = "stone";
    elementCombination["MudFire"] = "brick";
    elementCombination["FireMud"] = "brick";
    elementCombination["BrickBrick"] = "wall";
    elementCombination["SteamAir"] = "cloud";
    elementCombination["AirStean"] = "cloud";
    elementCombination["DustFire"] = "GunPowder";
    elementCombination["FireDust"] = "GunPowder";

    createdElement.push_back("Earth");
    createdElement.push_back("Water");
    createdElement.push_back("Air");
    createdElement.push_back("Fire");

    createdElement = {"Earth", "Water", "Air", "Fire"};
}


void ElementalEnigma::displayIntro() {
    std::cout << "✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣"<<std::endl;
    std::cout << "In the land where Mansa Musa's footsteps echo,\n";
    std::cout << "To find the Golden Scepter, the elements must flow.\n";
    std::cout << "Earth and fire dance so bright,\n";
    std::cout << "Lava's glow brings forth a guiding light.\n\n";
    std::cout << "In water's touch, the flames do cool,\n";
    std::cout << "A transformation starts, breaking the rule.\n";
    std::cout << "Obsidian forms, a path is clear,\n";
    std::cout << "Golden Scepter's secret drawing near.\n\n";
    std::cout << "Combine the elements, simple and true,\n";
    std::cout << "To unlock the power, reveal the view..\n\n";
    std::cout << "✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣"<<std::endl;
}

void ElementalEnigma::printDecorations(const std::string& dash) {
    std::cout << dash << std::endl;
}

void ElementalEnigma::printCreatedElements() {
    std::cout << "Created Elements: " << std::endl;
    for (const auto& element : createdElement) {
        std::cout << element << std::endl;
    }
}

void ElementalEnigma::combineElements() {
    bool obsidianCreated = false;
    std::string decorativeDash = "✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣";

    while (!obsidianCreated) {
        std::string element1, element2;
        std::cout << "₪Element 1: ";
        std::cin >> element1;
        std::cout << "₪Element 2: ";
        std::cin >> element2;
        printDecorations(decorativeDash);

        std::string combinationKey = element1 + element2;
        if (checkCombination(combinationKey)) {
            std::cout << "You combined " << element1 << " and " << element2 << " to create " << elementCombination[combinationKey] << std::endl;
            createdElement.push_back(elementCombination[combinationKey]);
            printDecorations(decorativeDash);
            printCreatedElements();
            printDecorations(decorativeDash);
            if (elementCombination[combinationKey] == "obsidian") {
                obsidianCreated = true;
            }
        } else {
            std::cout << "Invalid combination. Try again!\n";
        }
    }
}

bool ElementalEnigma::checkCombination(const std::string& combinationKey) {
    return elementCombination.find(combinationKey) != elementCombination.end();
}

void ElementalEnigma::displayEnding() {
    std::cout << "You've created obsidian and unlocked the portal to the hidden chamber of the Golden Scepter!\n";
}// Other member function implementations for ElementalEnigma

int ElementalEnigma::playGame() {
    displayIntro();
    printDecorations("✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣");

    std::cout << "₪ ELEMENTS: " << std::endl;
    printCreatedElements();
    combineElements();

    displayEnding();
    return 50;
}
//****************************************************************************************************************************************************/
// Implementation of NKO_Script

NKO_Script::NKO_Script() {
    initializeGame();
    correct = 0;
    score = 0;
}

void NKO_Script::initializeGame() {
    dictionary["\u07c0"] = 0;
    dictionary["\u07c1"] = 1;
    dictionary["\u07c2"] = 2;
    dictionary["\u07c3"] = 3;
    dictionary["\u07c4"] = 4;
    dictionary["\u07c5"] = 5;
    dictionary["\u07c6"] = 6;
    dictionary["\u07c7"] = 7;
    dictionary["\u07c8"] = 8;
    dictionary["\u07c9"] = 9;

    answer = {12, -4, 12, 16, 0, 96};
}

void NKO_Script::displayIntro() {
    std::cout <<"✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣" << std::endl;
    std::cout << "-----------" << "Dictionary" << "-----------" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (const auto& pair : dictionary) {
        std::cout << "N'KO Script: " << pair.first << "\t\tValue: " << pair.second << std::endl;
    }

    std::cout << "--------------------------------" << std::endl;
}

void NKO_Script::decodeThis() {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "___Unravel The Ancient Scroll___" << std::endl; 
    std::cout << "--------------------------------" << std::endl;
    std::cout <<"✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣" << std::endl;
    std::cout << std::endl;
    std::cout << "\u07c3" << " + " << "\u07c9" << std::endl;
    getUserInput();
    std::cout << "\u07c1 - \u07c5 = " << std::endl;
    getUserInput();
    std::cout << "\u07c2 * \u07c6 = " << std::endl;
    getUserInput();
    std::cout << "\u07c8 + \u07c8 = " << std::endl;
    getUserInput();
    std::cout << "\u07c7 - \u07c7 = " << std::endl;
    getUserInput();
    std::cout << "\u07c8\u07c9 + \u07c7 = " << std::endl;
    getUserInput();
    std::cout << std::endl;
    std::cout <<"✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣✣" << std::endl;
}

void NKO_Script::getUserInput() {
    int user_input;
    std::cin >> user_input;
    vector_input.push_back(user_input);
}

void NKO_Script::checkAnswer() {
    for (int i = 0; i < answer.size(); i++) { 
        if (answer[i] == vector_input[i]) {
            correct++;
        } else {
            correct--;
        }
    }
    score = correct * 10;
}

int NKO_Script::playGame() {
    displayIntro();
    decodeThis();
    checkAnswer();
    std::cout << "Score: " << score << std::endl;
    return score;
}
