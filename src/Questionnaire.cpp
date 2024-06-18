#include "questionnaire.h"

int Questionnaire::ask_and_evaluate() const {
    const auto& questions = ask_question();
    const auto& answers = getAnswerKey();
    std::vector<char> user_answers;

    for (size_t i = 0; i < questions.size(); ++i) {
        std::cout << questions[i];
        std::string user_answer;
        std::cin >> user_answer;
        
        // If the answer is not valid, treat it as incorrect
        if (user_answer.size() != 1 || (user_answer[0] != 'a' && user_answer[0] != 'b' && user_answer[0] != 'c')) {
            std::cout << "Please enter a valid answer (a, b, or c)." << std::endl;
            std::cout << "Incorrect. The correct answer is: " << answers[i] << std::endl;
            continue;
        }
        
        user_answers.push_back(user_answer[0]);

        if (std::tolower(user_answer[0]) == answers[i]) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect. The correct answer is: " << answers[i] << std::endl;
            std::cout << "Game Over!😫" << std::endl;
            exit(0);
        }
    }

    
    std::cout << "Sadio: Whew! That was close 😓" << std::endl;
    
    int score = evaluate_answers(user_answers);
    //std::cout << "You got " << score << " out of " << questions.size() << " questions correct." << std::endl;//
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return score;
}

std::vector<std::string> CouncilGriot::ask_question() const {
    return {
        "Which ruler is known for his hajj pilgrimage to Mecca?\n"
        "a) Mansa Musa (correct)\n"
        "b) Sundiata Keita\n"
        "c) Askia Muhammad\n",

        "Who is considered the founder of the Mali Empire?\n"
        "a) Mansa Musa\n"
        "b) Askia Muhammad\n"
        "c) Sundiata Keita (correct)\n",

        "What is the role of a griot?\n"
        "a) To keep stories and traditions alive through storytelling and music. (correct)\n"
        "b) To lead religious ceremonies and rituals.\n"
        "c) To manage trade relations with neighboring communities.\n"
    };
}

const std::vector<char>& CouncilGriot::getAnswerKey() const {
    return answerKey;
}

int CouncilGriot::evaluate_answers(const std::vector<char>& user_answers) const {
    int score = 0;
    for (size_t i = 0; i < user_answers.size(); ++i) {
        if (std::tolower(user_answers[i]) == answerKey[i]) {
            ++score;
        }
    }
    return score;
}


std::vector<std::string> DjenneGate::ask_question() const {
    return {
        "What is the traditional title of the ruler of the Mali Empire?\n"
        "a) Mansa (answer)\n"
        "b) Sultan\n"
        "c) Pharaoh\n"
    };
}

const std::vector<char>& DjenneGate::getAnswerKey() const {
    return answerKey;
}

int DjenneGate::evaluate_answers(const std::vector<char>& user_answers) const {
    int score = 0;
    for (size_t i = 0; i < user_answers.size(); ++i) {
        if (std::tolower(user_answers[i]) == answerKey[i]) {
            ++score; // Increment score when the answer is correct
        }
    }
    return score;
}

// In the DjenneGate class
int DjenneGate::getScore() const {
    return score;
}


