//
// Created by Jakub Čapek on 23.04.2022.
//

#include <limits>
#include "QuestionMultiChoice.h"

void QuestionMultiChoice::showQuestion()
{
    std::cout << text << "\n" << "\todpovidejte v libovolne kombinaci pismen abcd" << "\n"
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
        Common::getString(playerAnswer);
        if(not Common::checkABCDset(playerAnswer))
        {
            std::cout << "Odpovedeli jste ve spatnem formatu zkuste to znovu" << std::endl;
            Common::clearConsole();
        }
        else
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
        std::cout << "\nSpravna odpoved!" << std::endl;
        correctlyAnswered = true;
        return true;
    }
    std::cout << "\nSpatna odpoved!" << std::endl;
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

void QuestionMultiChoice::saveQuestion(std::ofstream& out)
{
    out << "\t{\n";
    out << "\t\t\"typ\" : << " << "2" << " >>" << std::endl;
    out << "\t\t\"text\" : << " << text << " >>" << std::endl;
    out << "\t\t\"spravna odpoved\" : << " << correctAnswer << " >>" << std::endl;
    for(int i = 0; i < 4; i++)
        out << "\t\t\"moznost\" : << " << options[i] << " >>" << std::endl;
    out << "\t}\n";
}

void QuestionMultiChoice::loadQuestion(std::ifstream& in)
{
    std::string input;
    std::getline(in, input, '\n');
    size_t from = input.find_first_of("<<");
    size_t to = input.find_first_of(">>");
    text = std::string(input.data() + from + 1, to-from);

    std::getline(in, input, '\n');
    from = input.find_first_of("<<");
    to = input.find_first_of(">>");
    correctAnswer = std::string(input.data() + from + 1, to-from);

    for(int i = 0; i < 4; i++)
    {
        std::getline(in, input, '\n');
        from = input.find_first_of("<<");
        to = input.find_first_of(">>");
        options[i] = std::string(input.data() + from + 1, to-from);
    }
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "\t}");
}

