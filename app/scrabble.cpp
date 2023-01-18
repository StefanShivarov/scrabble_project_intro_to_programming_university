#include <iostream>

void openMainMenu();

void printMenu()
{
    std::cout << "Welcome to Scrabble!\n-------------------------------\nMain Menu\n-------------------------------\n";
    std::cout << "1. New game\n2. Settings\n3. Add word to dictionary\n4. Exit\n";
    std::cout << "Choose an activity: ";
}

void startGame()
{
}

void openSettings()
{
}

void addWordToDictionary()
{
}

void handleIncorrectInput()
{
    std::cout << "Wrong command! No such option in the menu!" << std::endl;
    openMainMenu();
}

void openMainMenu()
{
    printMenu();
}

int main()
{

    openMainMenu();

    int menuOption;
    std::cin >> menuOption;

    switch (menuOption)
    {

    case 1:
        startGame();
        break;
    case 2:
        openSettings();
        break;
    case 3:
        addWordToDictionary();
        break;
    case 4:
        std::cout << "Exiting game...";
        break;
    default:
        handleIncorrectInput();
        break;
    }
}