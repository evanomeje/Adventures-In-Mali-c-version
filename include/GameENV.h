#ifndef GAMEENV_H
#define GAMEENV_H

#include <iostream>
#include "Questionnaire.h"
#include "PuzzleGame.h"
#include "InteractiveGame.h"
#include "MemoryGame.h"

#include <string>

class GameENV {
 public:
    GameENV(std::string level);
    virtual ~GameENV();
    virtual void interact() = 0;
    void printNPCSpeech(const std::string& speech) const;

 protected:
    std::string gamelvl;
};

class CityENV : public GameENV {
 public:
    CityENV(std::string game);
    ~CityENV() override;
    void interact() override;

 private:
    std::string gamelvl;
};

class TravelENV : public GameENV  {
 public:
    TravelENV(std::string game);
    ~TravelENV() override;
    void interact() override;

 private:
    std::string gamelvl;
};

class TempleENV : public GameENV {
 public:
    TempleENV(std::string game);
    ~TempleENV() override;
    void interact() override;

 private:
    std::string gamelvl;
};

#endif
