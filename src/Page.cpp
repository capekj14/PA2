//
// Created by Jakub Čapek on 22.04.2022.
//

#include <limits>
#include "Page.h"

void Page::showPage()
{
    for(auto& question : questions)
        question->showQuestion();
}

size_t Page::getQuestionCount()
{
    return questions.size();
}

int Page::getScore()
{
    int ret = 0;
    for(const auto& question : questions)
    {
        bool ok = question->getCorrectlyAnswered();
        if(ok)
            ret++;
    }
    return ret;
}

void Page::setIsAnswered(bool b)
{
    isAnswered = b;
}

int Page::run(int& falseStreak) //0 odpovezeno | 1 falseStreak >= 3 | 2 skip
{
    showPage();
    std::cout << "Pokud chcete na otazky odpovidat zadejte \"go\" pokud chcete stranku preskocit zadejte \"skip\"\n";
    while(true)
    {
        std::string input;
        std::cin >> input;
        if(input == "go")
            break;
        if(input == "skip")
            return 2;
        else
        {
            std::cout << "Nezvolili jste zadnou validni moznost, zkuste to znovu\n";
            Common::clearConsole();
        }
    }
    for(auto& question : questions)
    {
        bool goodAnswer = question->run();
        if(goodAnswer)
        {
            falseStreak = 0;
        }
        falseStreak++;
        if(falseStreak >= 3)
            return 2;
    }
    return 0;
}

void Page::addQuestion(const std::shared_ptr<Question>& question)
{
    questions.push_back(question);
}

void Page::createPage()
{
    QuizMaker::askQuestionCount(questionCount);
    for(int i = 0; i < questionCount; i++)
    {
        QuestionType type;
        QuizMaker::askQuestionType(type);
        switch (type)
        {
            case QuestionType::Free:
            {
                QuestionFreeAnswer question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionFreeAnswer>(question));
                break;
            }
            case QuestionType::SingleChoice:
            {
                QuestionSingleChoice question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionSingleChoice>(question));
                break;
            }
            case QuestionType::MultiChoice:
            {
                QuestionMultiChoice question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionMultiChoice>(question));
                break;
            }
            case QuestionType::YesNo:
            {
                QuestionYesNo question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionYesNo>(question));
                break;
            }
        }
    }
}

void Page::savePage(std::ofstream& out)
{
    out << "{\n";
    out << "\t\"pocet otazek\" : << " << questionCount << " >>" << std::endl;
    for(auto& question : questions)
        question->saveQuestion(out);
    out << "}\n";
}

void Page::loadPage(std::ifstream& in)
{
    std::string input;
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "{");
    std::getline(in, input, '\n');
    char loading [10] = {0};
    int readCount = sscanf(input.c_str(), "\t\"pocet otazek\" : << %s.9 >>", loading);
    if(readCount != 1)
        return;
    questionCount = strtol(loading, nullptr, 10);

    for(int i = 0; i < questionCount; i++)
    {
        std::getline(in, input, '\n');
        sscanf(input.c_str(), "\t{");
        std::getline(in, input, '\n');
        sscanf(input.c_str(), "\t\t\"typ\" : << %s >>", loading);

        int typeInt = strtol(loading, nullptr, 10);
        QuestionType type = (QuestionType) typeInt;
        switch(type)
        {
            case QuestionType::Free :
            {
                QuestionFreeAnswer question;
                questions.push_back(question.clone());//updated
                break;
            }
            case QuestionType::SingleChoice :
            {
                QuestionSingleChoice question;
                questions.push_back(question.clone());
                break;
            }
            case QuestionType::MultiChoice :
            {
                QuestionMultiChoice question;
                auto ptr = question.clone();
                questions.push_back(ptr);
                std::cout << "nespadlo" << std::endl;
                break;
            }
            case QuestionType::YesNo :
            {
                QuestionYesNo question;
                questions.push_back(question.clone());
                break;
            }
        }
        questions.back()->loadQuestion(in);
    }
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "}");
}
