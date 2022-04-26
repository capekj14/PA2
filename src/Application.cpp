//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Application.h"
#include "IOUnitQuiz.h"

void Application::createQuiz()
{
    QuizMaker quizMaker;
    quizMaker.run();
    //save
}

bool Application::loadQuiz()
{
    IOUnitQuiz ioUnit;
    std::cout << "Vyberte název kvízu z nabídky:" << std::endl;
    //printAll possible quizez
    std::string name;
    std::cin >> name;
    std::string quizName;
    ioUnit.load(name);
    return true;
}

void Application::showMenu()
{
    std::cout << "Vítejte v aplikaci Marast v2\n\n" << "\t1) Vytvořit nový kvíz\n" << "\t2) Načíst kvíz a hrát\n"
              << "\t3) Konec\n";
}

int Application::getAction()
{
    int ret;
    while(true)
    {
        std::cin >> ret;
        if (ret != 1 and ret != 2 and ret != 3)
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
    else if(result == 3)
        return;
    return;
}
