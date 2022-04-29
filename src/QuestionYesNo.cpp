//
// Created by Jakub Čapek on 23.04.2022.
//

#include <limits>
#include "QuestionYesNo.h"

void QuestionYesNo::showQuestion()
{
    std::cout << text << "\n" << "\todpovidejte \"ano\" nebo \"ne\" " << "\n"
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
            std::cout << "Odpovedeli jste ve spatnem formatu zkuste to znovu" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
        std::cout << "\nSpravna odpoved!" << std::endl;
        correctlyAnswered = true;
        return true;
    }
    else
    {
        correctlyAnswered = false;
        std::cout << "\nSpatna odpoved!" << std::endl;
        return false;
    }
}

QuestionType QuestionYesNo::getType() {
    return QuestionType::YesNo;
}

void QuestionYesNo::createQuestion()
{
    QuizMaker::askQuestionText(text);
    QuizMaker::askCorrectAnswerYesNo(correctAnswer);
}

void QuestionYesNo::saveQuestion(std::ofstream& out)
{
    out << "\t{\n";
    out << "\t\t\"typ\" : \"" << "4" << "\"" << std::endl;
    out << "\t\t\"text\" : \"" << text << "\"" << std::endl;
    out << "\t\t\"spravna odpoved\" : \"" << correctAnswer << "\"" << std::endl;
    out << "\t}\n";
}

void QuestionYesNo::loadQuestion(std::ifstream &) {

}
