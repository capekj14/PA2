cmake_minimum_required(VERSION 3.21)
project(semestralka)

set(CMAKE_CXX_STANDARD 14)

add_executable(semestralka src/main.cpp src/Application.cpp src/Application.h src/Quiz.cpp src/Quiz.h src/Page.cpp src/Page.h src/Question.cpp src/Question.h src/QuizMaker.cpp src/QuizMaker.h src/QuestionMultiChoice.cpp src/QuestionMultiChoice.h src/QuestionSingleChoice.cpp src/QuestionSingleChoice.h src/QuestionYesNo.cpp src/QuestionYesNo.h src/QuestionFreeAnswer.cpp src/QuestionFreeAnswer.h src/IOUnit.cpp src/IOUnit.h src/Player.cpp src/Player.h src/LeaderBoard.cpp src/LeaderBoard.h src/IOUnitQuiz.cpp src/IOUnitQuiz.h src/IOUnitLeaderBoard.cpp src/IOUnitLeaderBoard.h)
