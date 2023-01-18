#include <iostream>

int lettersPerRoundAmount = 10, roundsAmount = 10;

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

void changeLettersPerRoundAmount()
{
    std::cout << "Enter new letters amount: ";
    int newLettersAmount;
    std::cin >> newLettersAmount;
    lettersPerRoundAmount = newLettersAmount;
    std::cout << "\nSuccessfully set new letters per round amount to " << lettersPerRoundAmount << ". Back to main menu..." << std::endl;
    openMainMenu();
}

void changeRoundsAmount()
{
    std::cout << "Enter new rounds amount: ";
    int newRoundsAmount;
    std::cin >> newRoundsAmount;
    roundsAmount = newRoundsAmount;
    std::cout << "\nSuccessfully set new rounds amonut to " << roundsAmount << ". Back to main menu..." << std::endl;
    openMainMenu();
}

void openSettings()
{
    std::cout << "-------------------------------\nSettings\n-------------------------------\n";
    std::cout << "1. Change letters per round amount\n2. Change rounds amount\n3. Back to main menu.\n";
    std::cout << "Choose an option: ";
    int settingsOption;
    std::cin >> settingsOption;

    switch (settingsOption)
    {

    case 1:
        changeLettersPerRoundAmount();
        break;
    case 2:
        changeRoundsAmount();
        break;
    case 3:
        openMainMenu();
        break;
    default:
        std::cout << "Wrong command! No such option in the menu! Try again." << std::endl;
        openSettings();
        break;
    }
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