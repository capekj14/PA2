//
// Created by Jakub Čapek on 23.04.2022.
//

#include "QuestionMultiChoice.h"

void QuestionMultiChoice::showQuestion() const
{
    std::cout << text << "\t(odpovidejte v libovolne kombinaci pismen abcd)" << "\n"
              << "a)\t" << options[0] << "\n"
              << "b)\t" << options[1] << "\n"
              << "c)\t" << options[2] << "\n"
              << "d)\t" << options[3]
              << std::endl;
}

std::string QuestionMultiChoice::getAnswer()
{
    while (true)
    {
        Common::getString(playerAnswer);
        if (not Common::checkABCDSet(playerAnswer)) {
            std::cout << "Odpovedeli jste ve spatnem formatu zkuste to znovu" << std::endl;
        } else
            break;
    }
    return playerAnswer;
}

bool QuestionMultiChoice::evaluate()
{
    //checks if player answer contains same letters as correct answer
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
        std::cout << "Spatna odpoved!" << std::endl;
        correctlyAnswered = false;
        Common::sleep();
        return false;
    }
    if(correctSet == playerSet)
    {
        std::cout << "Spravna odpoved!" << std::endl;
        correctlyAnswered = true;
        Common::sleep();
        return true;
    }
    std::cout << "Spatna odpoved!" << std::endl;
    correctlyAnswered = false;
    Common::sleep();
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

void QuestionMultiChoice::saveQuestion(std::ofstream& out) const
{
    out << "\t{\n";
    out << "\t\t\"typ\" : << " << "1" << " >>" << std::endl;
    out << "\t\t\"text\" : << " << text << " >>" << std::endl;
    out << "\t\t\"spravna odpoved\" : << " << correctAnswer << " >>" << std::endl;
    for(int i = 0; i < 4; i++)
        out << "\t\t\"moznost\" : << " << options[i] << " >>" << std::endl;
    out << "\t}\n";
}

bool QuestionMultiChoice::loadQuestion(std::ifstream& in)
{
    std::string input;
    std::getline(in, input);
    text = Common::extractField(input);

    std::getline(in, input);
    correctAnswer = Common::extractField(input);

    for(int i = 0; i < 4; i++)
    {
        std::getline(in, input);
        std::string option = Common::extractField(input);
        options.push_back(std::move(option));
    }
    return true;
}
