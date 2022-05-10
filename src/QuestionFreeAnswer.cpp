//
// Created by Jakub Čapek on 23.04.2022.
//

#include <limits>
#include "QuestionFreeAnswer.h"

void QuestionFreeAnswer::showQuestion()
{
    std::cout << text << "\t(odpovidejte slovem ci vetou, neukoncujte teckou ani zadnym jinym znakem "
                                 "(bude hodnoceno jako spatna odpoved) )" << "\n"
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
            Common::clearConsole();
        }
        else
            break;
    }
    answered = true;
    return playerAnswer;
}

bool QuestionFreeAnswer::evaluate()
{
    if(playerAnswer == correctAnswer)
    {
        std::cout << "Spravna odpoved!" << std::endl;
        correctlyAnswered = true;
        Common::sleep();
        return true;
    }
    for (const auto& str: correctAnswerSet)
        if (str == playerAnswer)
        {
            std::cout << "Spravna odpoved!!" << std::endl;
            correctlyAnswered = true;
            Common::sleep();
            return true;
        }
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
//nyni vyhledava jestli playerAnswer obsahuje regex jako substring
bool QuestionFreeAnswer::checkBySubstring() {
    size_t i = 0;
    for (auto contIt = playerAnswer.begin(); contIt != playerAnswer.end(); ++contIt, ++i)
    {
        if(i + pattern.size() > playerAnswer.size())
            break;
        auto contCopy = contIt;
        bool flek = true;
        for (auto valIt = pattern.begin(); valIt != pattern.end(); ++valIt, ++contCopy)
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

void QuestionFreeAnswer::saveQuestion(std::ofstream& out)
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
    std::getline(in, input, '\n');
    size_t from = input.find_last_of("<<");
    size_t to = input.find_first_of(">>");
    if(from == input.size() or to == input.size() )
        return false;
    text = std::string(input.data() + from + 2, to - from - 3);

    std::getline(in, input, '\n');
    from = input.find_last_of("<<");
    to = input.find_first_of(">>");
    if(from == input.size() or to == input.size() )
        return false;
    correctAnswer = std::string(input.data() + from + 2, to - from - 3);

    std::getline(in, input, '\n');
    from = input.find_last_of("<<");
    to = input.find_first_of(">>");
    if(from == input.size() or to == input.size() )
        return false;
    pattern = std::string(input.data() + from + 2, to - from - 3);

    std::getline(in, input, '\n');
    char setCount[10] = {0};
    if(sscanf(input.c_str(), "\t\t\"pocet odpovedi v setu\" : <<%s.9>>", setCount) not_eq 1)
        return false;
    int iterateTo = strtol(setCount, nullptr, 10);

    for(int i = 0; i < iterateTo; i++)
    {
        std::getline(in, input, '\n');
        from = input.find_last_of("<<");
        to = input.find_first_of(">>");
        if(from == input.size() or to == input.size() )
            return false;
        correctAnswerSet.insert(std::string(input.data() + from + 2, to - from - 3));
    }
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "\t}");
    return true;
}

std::shared_ptr<Question> QuestionFreeAnswer::clone() const
{
    return std::make_shared<QuestionFreeAnswer>(*this);
}


