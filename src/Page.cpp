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
    Common::clearConsole();
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
            std::cout << "Nezvolili jste zadnou validni moznost, zkuste to znovu\n";
    }

    std::cout << "Muzete zacit odpovidat, postupujte shora dolu" << std::endl;
    for(auto& question : questions)
    {
        bool goodAnswer = question->run();
        if(goodAnswer)
            falseStreak = 0;
        else
            falseStreak++;
        
        if(falseStreak >= 3)
            return 1; //1 is state of exceeded failstreak
    }
    Common::clearConsole();
    return 0; //ok state
}

void Page::addPage(QuestionType type)
{
    switch(type)
    {
        case QuestionType::Free: 
            questions.push_back(std::make_shared<QuestionFreeAnswer>());
            break;
        case QuestionType::SingleChoice: 
            questions.push_back(std::make_shared<QuestionSingleChoice>());
            break;        
        case QuestionType::MultiChoice: 
            questions.push_back(std::make_shared<QuestionMultiChoice>());
            break;
        case QuestionType::YesNo: 
            questions.push_back(std::make_shared<QuestionYesNo>());
            break;
    }
}

void Page::createPage()
{
    QuizMaker::askQuestionCount(questionCount);
    for(int i = 0; i < questionCount; i++)
    {
        addPage(QuizMaker::askQuestionType());
        questions.back()->createQuestion();
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
    const auto enforceLineChar = [](auto& in, auto& str, char c){
        std::getline(in, str, '\n');
        return str.find(c) != (size_t)-1;
    };
    std::string input;
    if(enforceLineChar(in, input, '{') == false)
        return false;

    std::getline(in, input);
    auto useful = Common::skip(input, "\t\"pocet otazek\" : ");    
    std::string questionCount = Common::extractField(useful);
    auto [iterateTo, ok] = Common::strToInt(questionCount.data());
    if(ok == false)
        return false;

    for(int i = 0; i < iterateTo; i++)
    {
        if(enforceLineChar(in, input, '{') == false)
            return false;

        std::getline(in, input);
        std::string loaded = Common::extractField(input);
        auto [typeInt, ok] = Common::strToInt(loaded.data());
        if(not ok or typeInt < 0 or typeInt > 3)
            return false;

        QuestionType type = (QuestionType) typeInt;
        addPage(type);
        
        if(questions.back()->loadQuestion(in) not_eq 1)
            return false;
        
        if(enforceLineChar(in, input, '}') == false)
            return false;
    }

    if(enforceLineChar(in, input, '}') == false)
        return false;
    return true;
}

void Page::setPageInOrder(size_t num)
{
    pageInOrder = num;
}
