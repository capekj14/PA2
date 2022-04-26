//
// Created by Jakub Čapek on 23.04.2022.
//

#include "QuestionYesNo.h"

void QuestionYesNo::showQuestion()
{
    std::cout << text << "\n" << "\todpovídejte \"ano\" nebo \"ne\" " << "\n"
              << "ano\n"
              << "ne\n" << std::endl;
}

std::string QuestionYesNo::getAnswer()
{
    std::string answer;
    while (true)
    {
        std::cin >> answer;
        if(answer != "ano" and answer != "ne")
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

bool QuestionYesNo::evaluate()
{
    if( correctAnswer == playerAnswer)
    {
        std::cout << "\nSprávná odpověď!" << std::endl;
        correctlyAnswered = true;
        return true;
    }
    else
    {
        correctlyAnswered = false;
        std::cout << "\nŠpatná odpověď!" << std::endl;
        return false;
    }
}

QuestionType QuestionYesNo::getType() {
    return QuestionType::YesNo;
}
