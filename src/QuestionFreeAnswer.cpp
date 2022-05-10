//
// Created by Jakub Čapek on 23.04.2022.
//

#include "QuestionFreeAnswer.h"

void QuestionFreeAnswer::showQuestion() const
{
    std::cout << text << "\n(odpovidejte slovem ci vetou, neukoncujte teckou ani zadnym jinym znakem "
                                 "(bude hodnoceno jako spatna odpoved) )"
              << std::endl;
}

std::string QuestionFreeAnswer::getAnswer()
{
    while(true)
    {
        Common::getText(playerAnswer);
        if (playerAnswer.empty())
        {
            std::cout << "Neodpovedeli jste, zkuste to znovu" << std::endl;
            Common::resetConsole();
        }
        else
            break;
    }
    return playerAnswer;
}

bool QuestionFreeAnswer::evaluate()
{
    //tries player answer for exact match
    if(playerAnswer == correctAnswer)
    {
        std::cout << "Spravna odpoved!" << std::endl;
        correctlyAnswered = true;
        Common::sleep();
        return true;
    }
    //tries to match player answer with correct set answers
    for (const auto& str: correctAnswerSet)
        if (str == playerAnswer)
        {
            std::cout << "Spravna odpoved!!" << std::endl;
            correctlyAnswered = true;
            Common::sleep();
            return true;
        }
    //tries to find substring in player answer
    if(checkBySubstring())
    {
        std::cout << "Spravna odpoved!!" << std::endl;
        correctlyAnswered = true;
        Common::sleep();
        return true;
    }
    std::cout << "Spatna odpoved!\n";
    correctlyAnswered = false;
    Common::sleep();
    return false;
}

bool QuestionFreeAnswer::checkBySubstring() 
{
    return playerAnswer.find(pattern) != (size_t)-1;
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

void QuestionFreeAnswer::saveQuestion(std::ofstream& out) const
{
    out << "\t{\n";
    out << "\t\t\"typ\" : << " << "0" << " >>" << std::endl;
    out << "\t\t\"text\" : << " << text << " >>" << std::endl;
    out << "\t\t\"spravna odpoved\" : << " << correctAnswer << " >>" << std::endl;
    out << "\t\t\"regularni vyraz\" : << " << pattern << " >>" << std::endl;
    out << "\t\t\"pocet odpovedi v setu\" : << " << correctAnswerSet.size() << " >>" << std::endl;
    for(const auto& setAnswer : correctAnswerSet)
        out << "\t\t\"uznavana odpoved\" : << " << setAnswer << " >>" << std::endl;
    out << "\t}\n";
}



bool QuestionFreeAnswer::loadQuestion(std::ifstream& in)
{
    std::string input;
    std::getline(in, input);
    text = Common::extractField(input);

    std::getline(in, input);
    correctAnswer = Common::extractField(input);

    std::getline(in, input);
    pattern = Common::extractField(input);

    std::getline(in, input);
    auto useful = Common::skip(input, "\t\t\"pocet odpovedi v setu\" : ");
    
    std::string setCount = Common::extractField(useful);
    auto [iterateTo, ok] = Common::strToInt(setCount.data());
    if(ok == false)
        return false;

    for(int i = 0; i < iterateTo; i++)
    {
        std::getline(in, input);
        std::string answer = Common::extractField(input);
        correctAnswerSet.insert(std::move(answer));
    }
    
    return true;
}


