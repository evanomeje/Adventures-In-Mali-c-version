#include "GameENV.h"
#include <cstdlib>
#include <iostream>

using namespace std;

GameENV::GameENV(std::string level) {
    gamelvl = level;
}

GameENV::~GameENV() {}

void GameENV::interact() {}

CityENV::CityENV(std::string game) : GameENV(game) {
    gamelvl = game;
}

CityENV::~CityENV() {}

void CityENV::interact() {
    GameENV::interact();
    if (gamelvl == "TheGatesofDjenne") {
        DjenneGate djenneGate;
        std::cout << "GUARD: STOP! 😡" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "     : What's your business in Djenne, travelers?\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Sadio: Just passing through, we mean no harm. 🙏\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "GUARD: To enter our city you must prove ur knowledge!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
        djenneGate.ask_and_evaluate();
        std::cout << "########################################\n";
        std::cout << "⍟  You entered The city of Djenne 😁 ⍟\n";
        std::cout << "########################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");

        
    } else if (gamelvl == "TheMarketofDjenne") {
        std::cout << "###############################################\n";
        std::cout << "⍟  You entered The main Market of Djenne 😁 ⍟\n";
        std::cout << "###############################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system ("clear");
        std::cout << "Sadio: The city is bustling with activity today.\n"
                  << "       Traders from all corners of West-Africa\n"
                  << "       have gathered here to exchange goods.\n";
                  std::this_thread::sleep_for(std::chrono::seconds(7));
                  system("clear");

        std::cout << "#####################################################\n";
        std::cout << "⍟  You encounter a strange Merchant selling goods ⍟\n";
        std::cout << "#####################################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(4));
        system("clear");

        std::cout << "MERCHANT: Ah, my people! Welcome, welcome to my shop of wonders! \n"
                  << "          I dey feel say destiny don bring u pipu here for answers.\n"
                  << "          No worry sha, inside this small small shop wey I dey sell,\n"
                  << "          you go find the key wey you dey find.\n ";

        std::this_thread::sleep_for(std::chrono::seconds(10));
        system("clear");

        MarketChallenge TheMarketofDjenne;
        TheMarketofDjenne.playGame();
        system("clear");
        std::cout << "MERCHANT: Omo, you try well well! 🙌 You don gather all di things.\n"
                  << "          E go help you pass Niger River and meet Griots.\n"
                  << "          Dis mask, e get special power\n";
        std::this_thread::sleep_for(std::chrono::seconds(10));
        system("clear");
        
        } else if (gamelvl == "TheCouncilofGriots") {

        system("clear");
        std::cout << "Sadio: SHHHH I hear a conversation,💫\n";
        std::cout << "I think those are the griots the merchant told us about. 😮\n";
        std::cout << "We must listen carefully!\n";
        std::this_thread::sleep_for(std::chrono::seconds(6));
        system("clear");

std::cout << "✧･ﾟ:* [Kofi]: \"We must reflect on the grandeur of the Mali Empire, my brothers.\"\n"
          << "            \"It stands as a testament to the brilliance of our ancestors.\" *:･ﾟ✧\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Samba]: \"Indeed, my friend. The Mali Empire, under Sundiata Keita and his successors,\n"
          << "                 embodied the epitome of West African civilization.\" *:･ﾟ✧\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Oumar]: \"Ah, Sundiata Keita, the Lion King of Mali. His vision and leadership united our people.\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Kofi]: \"And let us not forget Mansa Musa, whose Hajj pilgrimage to Mecca elevated Mali to unparalleled prominence.\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Samba]:\"Ah, Mansa Musa, a true exemplar of wealth and opulence. His generosity left an indelible mark on our history.\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Oumar]:\"Indeed, his pilgrimage showcased Mali's prosperity and cultural richness to the world.\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Kofi]:\"But despite Mali's glory, we cannot overlook the challenges it faced.\"\n"
          << "             \"Internal strife, external pressures, all testing the resilience of our people.\" *:･ﾟ✧\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Samba]:\"True, my friend. The decline of the Mali Empire serves as a reminder of ever-changing tides of history.\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Oumar]:\"Yet, the legacy of Mali endures, woven into the fabric of West African heritage.\"\n"
          << "              \"It inspires future generations to strive for greatness.\" *:･ﾟ✧\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Kofi]:\"As griots, it's our sacred duty to keep the flames of Mali's history burning bright, brothers.✧･ﾟ:*\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));
std::cout << "✧･ﾟ:* [Samba]:\"Absolutely, Kofi. Through our songs and stories, we carry the weight of our civilization's legacy.\"\n";
std::this_thread::sleep_for(std::chrono::seconds(5));


 system("clear");
        std::cout << "##########################################################\n";
        std::cout << "✽ OBJECTIVE: Test your knowledge on the history of Mali ✽\n";
        std::cout << "##########################################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(8));

        

        CouncilGriot game;
        game.ask_and_evaluate();
        system("clear");
        std::cout << "[Kofi]: Now why where you listening to our conversation??🤬\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "Sadio: My brother please, we are just looking for the Hidden Temple of Kangaba😭\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "[Oumar]: Ahhh Kofi relax, you travelers must trek across the sahara desert.\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout << "[Samba]: Yes, Kofi is right the music and spirts will guide you there.\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
    } else {
        std::cout << "Invalid level specified." << std::endl;
    }
}

TravelENV::TravelENV(std::string game) : GameENV(game) {
    gamelvl = game;
}

TravelENV::~TravelENV() {}

void TravelENV::interact() {
    GameENV::interact();
    if (gamelvl == "TheRiverNigerCrossing") {
        std::cout << "Sadio: Ahhh look the River Niger is over there.💫\n" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        //system("clear");
    std::cout << "##################################################################################\n" << std::endl;
    std::cout << "✽ Fun Fact🤓: The River Niger is one of the major rivers in West Africa,"<< std::endl;
    std::cout << "✽ running through several countries from Guinea, Mali, Niger, Benin, and Nigeria."<< std::endl;
    std::cout << "✽ The River Niger has historically served as a crucial transportation route, for"<< std::endl;
    std::cout << "✽ the movement of trade and commerce across West Africa."<<std::endl;
    std::cout << "##################################################################################\n" << std::endl;


          std::this_thread::sleep_for(std::chrono::seconds(10));
          system("clear");

        std::cout << "##############################################\n";
        std::cout << "✽ OBJECTIVE: You must cross the Niger River ✽\n";
        std::cout << "##############################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(8));
         system("clear");

        Maze River_Niger_Maze;
        River_Niger_Maze.playGame();

        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");

    } else if (gamelvl == "TheLostCaravan") {

        std::cout << "Sadio: Ahh look I see the Sahara Desert!💫\n";
        std::this_thread::sleep_for(std::chrono::seconds(4));
        //system("clear");

        std::cout << "✽ Fun Fact🤓: The Sahara Desert is the largest hot desert in the world,\n";
        std::cout << "✽ covering an area of approximately 9.2 million square km! \n";
        
        std::this_thread::sleep_for(std::chrono::seconds(4));
        system("clear");
        
        std::cout << "#########################################\n";
        std::cout << "✽ OBJECTIVE: You must follow the path! ✽\n";
        std::cout << "#########################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(8));
        system("clear");
        LostCarvan The_Lost_Caravan;
        The_Lost_Caravan.play();
        system("clear");
    } else if (gamelvl == "TheMusicofTheDunes") {
        std::cout << "Sadio: Ahh look I hear music!💫\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
        std::cout << "This what the merchant was talking about,\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
        std::cout << "we must follow the direction!\n";
        std::this_thread::sleep_for(std::chrono::seconds(7));
        system("clear");
        std::cout << "#########################################\n";
        std::cout << "✽ OBJECTIVE: You must follow the path! ✽\n";
        std::cout << "#########################################\n";
        MusicDune The_Music_of_The_Dunes;
        The_Music_of_The_Dunes.play();
        system("clear");
    } else if (gamelvl == "TheMysticOasis") {
    std::cout << "Sadio: We will soon reach the Temple of Kangaba!💫\n";
    std::cout << "Legends say the Sahara contains a magic oasis that can transport us.\n";
    std::cout << "We have to be careful; it contains a very deadly snake. Making it angry can kill you!\n";
     std::this_thread::sleep_for(std::chrono::seconds(8));
    system("clear");
        std::cout << "########################################################\n";
        std::cout << "✽ OBJECTIVE: You must feed the snake the right words! ✽\n";
        std::cout << "########################################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        Snake The_Mystic_Oasis;
        The_Mystic_Oasis.playGame();
    system("clear");
    } else {
        std::cout << "Invalid level specified." << std::endl;
    }
}

TempleENV::TempleENV(std::string game) : GameENV(game) {
    gamelvl = game;
}

TempleENV::~TempleENV() {}

void TempleENV::interact() {
    GameENV::interact();
    if (gamelvl == "TheHiddenTempleofKangaba") {
        std::cout << "Sadio: Look at that, we have reached the Temple of Kangaba!💫\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");
        std::cout << "###########################################\n";
        std::cout << "✽ OBJECTIVE: You must decode the script! ✽\n";
        std::cout << "###########################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("clear");

        int kangaba_score;

        NKO_Script TheHiddenTempleofKangaba;
        TheHiddenTempleofKangaba.playGame();
        system("clear");
        std::cout << "⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟\n";
        std::cout << "⍟  Uhoh the temple starts to shake! ⍟\n";
        std::cout << "⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟⍟\n";
        std::this_thread::sleep_for(std::chrono::seconds(6));
        system("clear");
        std::cout << "Sadio: Oh no, we must align the elemets before its too late!😯\n";
        std::this_thread::sleep_for(std::chrono::seconds(4));
    } else if (gamelvl == "score") {
        system("clear");
         system("clear");
        std::cout << "###########################################################\n";
        std::cout << "✽ OBJECTIVE: Solve the Riddle by combining the elements! ✽\n";
        std::cout << "###########################################################\n";
        std::this_thread::sleep_for(std::chrono::seconds(8));
        ElementalEnigma The_Elemental_Enigma;
        int elementScore = The_Elemental_Enigma.playGame();
        system("clear");
        std::cout << "Sadio: Wow!!! Good job!!!😯\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        

        int totalScore = elementScore * 2;

     std::cout <<"##################"<<std::endl;
     std::cout << "Game Score: " << totalScore<< std::endl;
     std::cout <<"##################"<<std::endl;
     std::this_thread::sleep_for(std::chrono::seconds(5));

     std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
    } else {
        std::cout << "Invalid level specified." << std::endl;
    }
}
