#include <gtest/gtest.h>
#include "questionnaire.h"

TEST(QuestionnaireTest, AskAndEvaluateTest) {
  // Mock questions and answers
  std::vector<std::string> questions = {
    "Question 1?",
    "Question 2?",
    "Question 3?"
  };
  std::vector<char> answers = { 'a', 'c', 'a' };

  MockQuestion mock(questions, answers);

  mock.outputQuestions(std::cout);

  ASSERT_EQ(questions[0], "Question 1?");

  int score = mock.ask_and_evaluate();

  EXPECT_EQ(score, 3);
}

TEST(CouncilGriotTest, EvaluateAnswersTest) {
  CouncilGriot councilGriot;
  std::vector<char> userAnswers = { 'a', 'c', 'a' };
  int score = councilGriot.evaluate_answers(userAnswers);
  EXPECT_EQ(score, 3);
}

TEST(DjenneGateTest, EvaluateAnswersTest) {
  DjenneGate djenneGate;
  std::vector<char> userAnswers = { 'c' };
  int score = djenneGate.evaluate_answers(userAnswers);
  EXPECT_EQ(score, 0);
}
