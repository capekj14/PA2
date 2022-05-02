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
        Common::getString(playerAnswer);
        if(playerAnswer != "ano" and playerAnswer != "ne")
        {
            std::cout << "Odpovedeli jste ve spatnem formatu zkuste to znovu" << std::endl;
            Common::clearConsole();
        }
        else
            break;
    }
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
    out << "\t\t\"typ\" : << " << "4" << " >>" << std::endl;
    out << "\t\t\"text\" : << " << text << " >>" << std::endl;
    out << "\t\t\"spravna odpoved\" : << " << correctAnswer << " >>" << std::endl;
    out << "\t}\n";
}

void QuestionYesNo::loadQuestion(std::ifstream& in)
{
    std::string input;
    std::getline(in, input, '\n');
    size_t from = input.find_first_of("<<");
    size_t to = input.find_first_of(">>");
    text = std::string(input.data() + from + 1, to-from);

    std::getline(in, input, '\n');
    std::string setCount;
    sscanf(input.c_str(), "\t\t\"spravna odpoved\" : <<%s>>", &correctAnswer);

    std::getline(in, input, '\n');
    sscanf(input.c_str(), "\t}");
}
