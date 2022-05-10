//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Page.h"

void Page::showPage() const
{
    std::cout << "Stranka: " << pageInOrder + 1 << std::endl;
    for(auto& question : questions)
        question->showQuestion();
}

size_t Page::getQuestionCount() const
{
    return questions.size();
}

int Page::getScore() const
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

int Page::run(int& falseStreak)
{
    Common::deleteConsole();
    showPage();
    std::cout << "Pokud chcete na otazky odpovidat zadejte \"go\" pokud chcete stranku preskocit zadejte \"skip\"\n";
    while(true)
    {
        std::string input;
        Common::getString(input);
        if(input == "go")
            break;
        if(input == "skip") //2 is state of skipped page
            return 2;
        else
        {
            std::cout << "Nezvolili jste zadnou validni moznost, zkuste to znovu\n";
        }
    }
    std::cout << "Muzete zacit odpovidat, postupujte shora dolu" << std::endl;
    for(auto& question : questions)
    {
        bool goodAnswer = question->run();
        if(goodAnswer)
        {
            falseStreak = 0;
        }
        else
            falseStreak++;
        if(falseStreak >= 3)
        {
            return 1; //1 is state of exceeded failstreak
        }
    }
    Common::deleteConsole();
    return 0; //ok state
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

void Page::savePage(std::ofstream& out) const
{
    out << "{\n";
    out << "\t\"pocet otazek\" : << " << questionCount << " >>" << std::endl;
    for(auto& question : questions)
        question->saveQuestion(out);
    out << "}\n";
}

bool Page::loadPage(std::ifstream& in)
{
    std::string input;
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "{");
    std::getline(in, input, '\n');
    char loading [10] = {0};
    int readCount = sscanf(input.c_str(), "\t\"pocet otazek\" : << %s.9 >>", loading);
    if(readCount not_eq 1)
        return false;
    questionCount = strtol(loading, nullptr, 10);

    for(int i = 0; i < questionCount; i++)
    {
        std::getline(in, input, '\n');
        sscanf(input.c_str(), "\t{");
        std::getline(in, input, '\n');
        if(sscanf(input.c_str(), "\t\t\"typ\" : << %s >>", loading) not_eq 1)
            return false;
        int typeInt = strtol(loading, nullptr, 10);
        if(typeInt < 0 or typeInt > 3)
            return false;
        QuestionType type = (QuestionType) typeInt;
        switch(type)
        {
            case QuestionType::Free :
            {
                QuestionFreeAnswer question;
                questions.push_back(question.clone());
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
                questions.push_back(question.clone());
                break;
            }
            case QuestionType::YesNo :
            {
                QuestionYesNo question;
                questions.push_back(question.clone());
                break;
            }
        }
        if(questions.back()->loadQuestion(in) not_eq 1)
            return false;
    }
    std::getline(in, input, '\n');
    sscanf(input.c_str(), "}");
    return true;
}

void Page::setPageInOrder(size_t num)
{
    pageInOrder = num;
}
