//
// Created by Jakub Čapek on 23.04.2022.
//

#include "QuestionSingleChoice.h"

void QuestionSingleChoice::showQuestion()
{
    std::cout << text << "\n" << "\todpovídejte \"a\", \"b\", \"c\" nebo \"d\" " << "\n"
              << "a\t" << options[0]
              << "b\t" << options[1]
              << "c\t" << options[2]
              << "d\t" << options[3]
              << std::endl;
}

std::string QuestionSingleChoice::getAnswer()
{
    std::string answer;
    while (true)
    {
        std::cin >> answer;
        if(answer != "a" and answer != "b" and answer != "c" and answer != "d")
        {
            std::cout << "Odpověděli jste ve špatném formátu zkuste to znovu" << std::endl;
        }
        else
            break;
    }
    playerAnswer = answer;
    answered = true;
    return answer;
}

bool QuestionSingleChoice::evaluate()
{
    if( correctAnswer == playerAnswer)
    {
        correctlyAnswered = true;
        return true;
    }
    else
    {
        correctlyAnswered = false;
        return false;
    }
}
