#include "GameENV.h"

#include <cstdlib>
#include <iostream>


int main() {
    system("clear");
    std::string PlayerName;
    std::string choice;

    std::cout << "Enter Name: " << std::endl;
    std::cin >> PlayerName;
    system("clear");

std::cout << "Hello, " << PlayerName << ", welcome to the a"
         << "ncient land of Mali. My name is Sadio,\n"
          << "I will be guiding you through"
          << " the legendary city of Djenne, surrounded\n"
          << "by whispers of its rich history and hidden treasures.\n"
              << "❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃"
              << "❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃"
              <<"❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃\n"
              << "❃❃❃ Are you ready to embark on a"
              << "journey of discovery and adventure?(y/n) ❃❃❃\n"
              << "❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃"
              << "❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃"
              << "❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃❃\n";
    std::cin >> choice;

    if (choice == "yes" || choice == "y" || choice == "Y") {
        system("clear");

        GameENV* level_1 = new CityENV("TheGatesofDjenne");

        DjenneGate gate;
        level_1->interact();
        delete level_1;

        system("clear");

        GameENV* level_2 = new CityENV("TheMarketofDjenne");
        level_2->interact();
        delete level_2;

        system("clear");

        GameENV* level_3 = new TravelENV("TheRiverNigerCrossing");
        level_3->interact();
        delete level_3;

        system("clear");

        GameENV* level_4 = new CityENV("TheCouncilofGriots");
        level_4->interact();
        delete level_4;

        system("clear");

        GameENV* level_5 = new TravelENV("TheLostCaravan");
        level_5->interact();
        delete level_5;

        system("clear");

        GameENV* level_6 = new TravelENV("TheMusicofTheDunes");
        level_6->interact();
        delete level_6;

        system("clear");

        GameENV* level_7 = new TravelENV("TheMysticOasis");
        level_7->interact();
        delete level_7;

        system("clear");

        GameENV* level_8 = new TempleENV("TheHiddenTempleofKangaba");
        level_8->interact();
        delete level_8;

        system("clear");

        GameENV* level_9 = new TempleENV("score");
        //level_9->interact();
        level_9->interact();
        delete level_9;

        system("clear");


    } else {
        std::cout << "Sorry to see you go :(" << std::endl;
    }

    return 0;
}
