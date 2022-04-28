//
// Created by Jakub Čapek on 23.04.2022.
//

#include "QuestionMultiChoice.h"

void QuestionMultiChoice::showQuestion()
{
    std::cout << text << "\n" << "\todpovídejte v libovolné kombinaci písmen abcd" << "\n"
              << "a\t" << options[0]
              << "b\t" << options[1]
              << "c\t" << options[2]
              << "d\t" << options[3]
              << std::endl;
}

std::string QuestionMultiChoice::getAnswer()
{
    std::string answer;
    while (true)
    {
        bool ok = true;
        std::cin >> answer;
        for(auto & character : answer)
        {
            if (character != 'a' and character != 'b' and character != 'c' and character != 'd')
            {
                ok = false;
                std::cout << "Odpověděli jste ve špatném formátu zkuste to znovu" << std::endl;
            }
        }
        if(ok)
            break;
    }
    playerAnswer = answer;
    answered = true;
    return answer;
}

bool QuestionMultiChoice::evaluate()
{
    std::set<char> correctSet;
    for(char c : correctAnswer)
    {
        correctSet.insert(c);
    }
    std::set<char> playerSet;
    for(char c : playerAnswer)
    {
        playerSet.insert(c);
    }
    if(correctSet.size() != playerSet.size())
    {
        correctlyAnswered = false;
        return false;
    }
    if(correctSet == playerSet)
    {
        std::cout << "\nSprávná odpověď!" << std::endl;
        correctlyAnswered = true;
        return true;
    }
    std::cout << "\nŠpatná odpověď!" << std::endl;
    correctlyAnswered = false;
    return false;
}

QuestionType QuestionMultiChoice::getType() {
    return QuestionType::MultiChoice;
}

void QuestionMultiChoice::createQuestion()
{
    QuizMaker::askQuestionText(text);
    QuizMaker::askOptions(options);
    QuizMaker::askCorrectAnswerMulti(correctAnswer);
}

