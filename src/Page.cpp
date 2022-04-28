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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
            }
            case QuestionType::SingleChoice:
            {
                QuestionSingleChoice question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionSingleChoice>(question));
            }
            case QuestionType::MultiChoice:
            {
                QuestionMultiChoice question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionMultiChoice>(question));
            }
            case QuestionType::YesNo:
            {
                QuestionYesNo question;
                question.createQuestion();
                questions.push_back(std::make_shared<QuestionYesNo>(question));
            }
        }
    }
}
