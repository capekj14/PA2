//
// Created by Jakub Čapek on 23.04.2022.
//

#include <limits>
#include "QuestionYesNo.h"

void QuestionYesNo::showQuestion() const
{
    std::cout << text << "\t(odpovidejte \"ano\" nebo \"ne\")" << std::endl;
}

std::string QuestionYesNo::getAnswer()
{
    while (true)
    {
        Common::getString(playerAnswer);
        if(playerAnswer != "ano" and playerAnswer != "ne")
        {
            std::cout << "Odpovedeli jste ve spatnem formatu zkuste to znovu" << std::endl;
        }
        else
            break;
    }
    return playerAnswer;
}

bool QuestionYesNo::evaluate()
{
    if( correctAnswer == playerAnswer)
    {
        std::cout << "Spravna odpoved!" << std::endl;
        correctlyAnswered = true;
        Common::sleep();
        return true;
    }
    else
    {
        correctlyAnswered = false;
        std::cout << "Spatna odpoved!" << std::endl;
        Common::sleep();
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

void QuestionYesNo::saveQuestion(std::ofstream& out) const
{
    out << "\t{\n";
    out << "\t\t\"typ\" : << " << "3" << " >>" << std::endl;
    out << "\t\t\"text\" : << " << text << " >>" << std::endl;
    out << "\t\t\"spravna odpoved\" : << " << correctAnswer << " >>" << std::endl;
    out << "\t}\n";
}

bool QuestionYesNo::loadQuestion(std::ifstream& in)
{
    std::string input;
    std::getline(in, input);
    text = Common::extractField(input);
    
    std::getline(in, input);
    auto useful = Common::skip(input, "\t\t\"spravna odpoved\" : ");
    
    correctAnswer = Common::extractField(useful);

    return true;
}