//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Application.h"

void Application::createQuiz()
{
    quiz.createQuiz();
    quiz.saveQuiz();
}

bool Application::loadQuiz()
{
    std::cout << "Vyberte nazev kvizu z nabidky:" << std::endl;
    findQuizes();
    std::string str;
    std::cin >> str;
    quiz.setName(str);
    quiz.loadQuiz();
    return true;
}

void Application::showMenu()
{
    std::cout << "Vitejte v aplikaci Marast v2\n\n" << "\t1) Vytvorit novy kviz\n" << "\t2) Nacist kviz a hrat\n"
              << "\t3) Konec\n";
}

int Application::getAction()
{
    while(true)
    {
        int ret;
        std::cin >> ret;
        if (ret != 1 and ret != 2 and ret != 3)
        {
            std::cout << "Zadali jste neplatnou moznost, zkuste to znovu" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
            return ret;
    }
}

void Application::run()
{
    while(true)
    {
        showMenu();
        int result = getAction();
        if(result == 1)
        {
            quiz.loadQuiz();
            quiz.run();
        }
        else if(result == 2)
        {
            quiz.createQuiz();
        }
        else if(result == 3)
            break;
    }
}

void Application::findQuizes()
{
    for(const auto& item : std::filesystem::directory_iterator("/semestralka/quizes"))
    {
        std::cout << item << std::endl;
    }
}
