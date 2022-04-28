//
// Created by Jakub Čapek on 23.04.2022.
//

#include "QuestionFreeAnswer.h"

void QuestionFreeAnswer::showQuestion()
{
    std::cout << text << "\n" << "\todpovídejte slovem či větou, neukončujte tečkou ani žádným jiným znakem "
                                 "(bude hodnoceno jako špatná odpověď)" << "\n"
              << std::endl;
}

std::string QuestionFreeAnswer::getAnswer()
{
    std::string answer;
    while(true)
    {
        std::cin >> answer;
        if (answer.empty())
            std::cout << "Neodpověděli jste, zkuste to znovu" << std::endl;
        else
            break;
    }
    playerAnswer = answer;
    return answer;
}

bool QuestionFreeAnswer::evaluate()
{
    if(playerAnswer == correctAnswer)
    {
        std::cout << "\nSprávná odpověď!" << std::endl;
        correctlyAnswered = true;
        return true;
    }
    for (const auto& str: correctAnswerSet)
        if (str == playerAnswer)
        {
            std::cout << "\nSprávná odpověď!" << std::endl;
            correctlyAnswered = true;
            return true;
        }
    if(checkByRegex(playerAnswer))
    {
        std::cout << "\nSprávná odpověď!" << std::endl;
        correctlyAnswered = true;
        return true;
    }
    std::cout << "\nŠpatná odpověď\n";
    correctlyAnswered = false;
    return false;
}
//nyni vyhledava jestli playerAnswer obsahuje regex jako substring
bool QuestionFreeAnswer::checkByRegex(const std::string &str)
{
    size_t i = 0;
    for (auto contIt = playerAnswer.begin(); contIt != playerAnswer.end(); ++contIt, ++i)
    {
        if(i + str.size() > str.size())
            break;
        auto contCopy = contIt;
        bool flek = true;
        for (auto valIt = str.begin(); valIt != str.end(); ++valIt, ++contCopy)
        {
            bool is_equal = *contCopy == *valIt;
            if(!is_equal)
            {
                flek = false;
                break;
            }
        }
        if(flek)
            return true;
    }
    return false;
}

QuestionType QuestionFreeAnswer::getType()
{
    return QuestionType::Free;
}

void QuestionFreeAnswer::createQuestion()
{
    QuizMaker::askQuestionText(text);
    QuizMaker::askCorrectAnswerFree(correctAnswer, pattern, correctAnswerSet);
}

