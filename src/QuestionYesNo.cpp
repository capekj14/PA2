//
// Created by Jakub Čapek on 23.04.2022.
//

#include <limits>
#include "QuestionYesNo.h"

void QuestionYesNo::showQuestion()
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
            Common::clearConsole();
        }
        else
            break;
    }
    answered = true;
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

void QuestionYesNo::saveQuestion(std::ofstream& out)
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
    std::getline(in, input, '\n');
    size_t from = input.find_last_of("<<");
    size_t to = input.find_first_of(">>");
    if(from == input.size() or to == input.size() )
        return false;
    text = std::string(input.data() + from + 2, to - from - 3);

    std::getline(in, input, '\n');
    char corrAnswer [5] = {0};
    if(sscanf(input.c_str(), "\t\t\"spravna odpoved\" : <<%s.4>>", corrAnswer) not_eq 1)
        return false;
    correctAnswer = corrAnswer;

    std::getline(in, input, '\n');
    sscanf(input.c_str(), "\t}");
    return true;
}

std::shared_ptr<Question> QuestionYesNo::clone() const
{
    return std::make_shared<QuestionYesNo>(*this);
}