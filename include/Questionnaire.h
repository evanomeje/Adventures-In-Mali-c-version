#ifndef QUESTIONNAIRE_H_INCLUDED
#define QUESTIONNAIRE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cstdlib>
#include <thread>

class Questionnaire {
protected:
//int score = 0;

public:
    virtual std::vector<std::string> ask_question() const = 0;
    virtual const std::vector<char>& getAnswerKey() const = 0;
    virtual int evaluate_answers(const std::vector<char>& user_answers) const = 0;

    int ask_and_evaluate() const;
  // int getScore() const;//
};

class CouncilGriot : public Questionnaire {
private:
    std::vector<char> answerKey = {'a', 'c', 'a'};

public:
    std::vector<std::string> ask_question() const override;
    const std::vector<char>& getAnswerKey() const override;
    int evaluate_answers(const std::vector<char>& user_answers) const override;
};

class DjenneGate : public Questionnaire {
private:
    std::vector<char> answerKey = {'a'};
    int score = 0;

public:
    std::vector<std::string> ask_question() const override;
    const std::vector<char>& getAnswerKey() const override;
    int evaluate_answers(const std::vector<char>& user_answers) const override;
     int getScore() const;
};

#endif
