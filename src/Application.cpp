//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Application.h"

void Application::createQuiz()
{
    QuizMaker quizMaker;
    quizMaker.run();
}

bool Application::loadQuiz()
{
    IOUnit ioUnit;
    //printAll possible quizez
    //select one
    std::string quizName;
    ioUnit.loadQuiz();
    return false;
}

void Application::showMenu()
{
    std::cout << "Vítejte v aplikaci Marast v2\n\n" << "\t1) Vytvořit nový kvíz\n" << "\t2) Načíst kvíz a hrát\n";
}

int Application::getAction()
{
    int ret;
    while(true)
    {
        std::cin >> ret;
        if (ret != 1 and ret != 2)
        {
            std::cout << "Zadali jste neplatnou možnost, zkuste to znovu " << std::endl;
        }
        else
            break;
    }
    return ret;
}

void Application::run()
{
    showMenu();
    int result = getAction();
    if(result == 1)
    {
        if(!loadQuiz())
        {
            std::cout << "Nelze otevřít zadaný kvíz " << std::endl;
            return;
        }
        quiz.run();
    }
    else if(result == 2)
    {
        createQuiz();
    }
    return;
}
