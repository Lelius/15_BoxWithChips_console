#include <iostream>
#include <Windows.h>
#include <string>

#include "BoxMainMenu.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    BoxMainMenu *mainMenu = new BoxMainMenu();
    mainMenu->startMainMenu();

    cin.get();

    delete mainMenu;
    return 0;
}