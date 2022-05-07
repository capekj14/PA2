//
// Created by Jakub Čapek on 23.04.2022.
//

#include <limits>
#include "QuestionSingleChoice.h"

void QuestionSingleChoice::showQuestion()
{
    std::cout << text << "\n" << "\todpovidejte \"a\", \"b\", \"c\" nebo \"d\" " << "\n"
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
        Common::getString(playerAnswer);
        if(playerAnswer != "a" and playerAnswer != "b" and playerAnswer != "c" and playerAnswer != "d")
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

bool QuestionSingleChoice::evaluate()
{
    if( correctAnswer == playerAnswer)
    {
        correctlyAnswered = true;
        std::cout << "\nSpravna odpoved!" << std::endl;
        return true;
    }
    else
    {
        correctlyAnswered = false;
        std::cout << "\nSpatna odpoved!" << std::endl;
        return false;
    }
}

QuestionType QuestionSingleChoice::getType()
{
    return QuestionType::SingleChoice;
}

void QuestionSingleChoice::createQuestion()
{
    QuizMaker::askQuestionText(text);
    QuizMaker::askOptions(options);
    QuizMaker::askCorrectAnswerSingle(correctAnswer);

}

void QuestionSingleChoice::saveQuestion(std::ofstream& out)
{
    out << "\t{\n";
    out << "\t\t\"typ\" : << " << "2" << " >>" << std::endl;
    out << "\t\t\"text\" : << " << text << " >>" << std::endl;
    out << "\t\t\"spravna odpoved\" : << " << correctAnswer << " >>" << std::endl;
    for(int i = 0; i < 4; i++)
        out << "\t\t\"moznost\" : << " << options[i] << " >>" << std::endl;
    out << "\t}\n";
}

void QuestionSingleChoice::loadQuestion(std::ifstream& in)
{
    std::string input;
    std::getline(in, input, '\n');
    size_t from = input.find_last_of("<<");
    size_t to = input.find_first_of(">>");
    text = std::string(input.data() + from + 2, to - from - 3);

    std::getline(in, input, '\n');
    from = input.find_last_of("<<");
    to = input.find_first_of(">>");
    correctAnswer = std::string(input.data() + from + 2, to - from - 3);

    for(int i = 0; i < 4; i++)
    {
        std::getline(in, input, '\n');
        from = input.find_last_of("<<");
        to = input.find_first_of(">>");
        options[i] = std::string(input.data() + from + 2, to - from - 3);
    }
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "\t}");
}

std::shared_ptr<Question> QuestionSingleChoice::clone() const
{
    return std::make_shared<QuestionSingleChoice>(*this);
}