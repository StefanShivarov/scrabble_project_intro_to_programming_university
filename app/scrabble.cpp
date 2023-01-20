#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>

int lettersPerRoundAmount = 10, roundsAmount = 10;
const int lowestAsciiLetterIndex = 97, highestAsciiLetterIndex = 122;
const std::string dictionaryFilePath = "..\\resources\\dictionary.txt";

void openMainMenu();

void printGivenLetters(char letters[])
{
    for (int i = 0; i < lettersPerRoundAmount; i++)
    {
        std::cout << letters[i] << " ";
    }
    std::cout << "\n";
}

bool wordContainsProvidedLettersOnly(std::string word, char letters[])
{
    bool letterIsGiven;
    char lettersCopy[lettersPerRoundAmount];
    strcpy(lettersCopy, letters);
    for (int i = 0; i < word.length(); i++)
    {
        letterIsGiven = false;
        for (int j = 0; j < lettersPerRoundAmount; j++)
        {
            if (lettersCopy[j] == word[i])
            {
                lettersCopy[j] = '0';
                letterIsGiven = true;
                break;
            }
        }

        if (!letterIsGiven)
        {
            return false;
        }
    }
    return true;
}

void printMenu()
{
    std::cout << "Welcome to Scrabble!\n-------------------------------\nMain Menu\n-------------------------------\n";
    std::cout << "1. New game\n2. Settings\n3. Add word to dictionary\n4. Exit\n";
    std::cout << "Choose an activity: ";
}

bool areSameWords(std::string word1, std::string word2)
{
    if (word1.length() != word2.length())
    {
        return false;
    }

    for (int i = 0; i < word1.length(); i++)
    {
        if (word1[i] != word2[i])
        {
            return false;
        }
    }

    return true;
}

bool dictionaryContainsWord(std::string word)
{

    std::fstream readDictionaryFile;
    readDictionaryFile.open(dictionaryFilePath, std::fstream::in);
    std::string buffer;
    while (std::getline(readDictionaryFile, buffer))
    {
        if (areSameWords(word, buffer))
        {
            readDictionaryFile.close();
            return true;
        }
    }

    readDictionaryFile.close();
    return false;
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

void handleIncorrectInput()
{
    std::cout << "Wrong command! No such option in the menu!" << std::endl;
    openMainMenu();
}

void addWordToDictionary()
{
    std::fstream addWordStream;
    addWordStream.open(dictionaryFilePath, std::fstream::out | std::fstream::app);
    std::cout << "Type a word to add to the dictionary: " << std::endl;
    std::string word;
    std::cin >> word;
    addWordStream << word << "\n";
    addWordStream.close();
    std::cout << word << " successfully added to dictionary! Back to main menu..." << std::endl;
    openMainMenu();
}

void startGame()
{
    int points = 0;
    srand(time(0));

    std::string word;
    for (int currentRound = 1; currentRound <= roundsAmount; currentRound++)
    {

        char availableLettersArr[lettersPerRoundAmount];
        std::cout << "\nRound " << currentRound << ". Available letters: ";
        for (int i = 0; i < lettersPerRoundAmount; i++)
        {

            availableLettersArr[i] = (char)((rand() % (highestAsciiLetterIndex - lowestAsciiLetterIndex + 1)) + lowestAsciiLetterIndex);
            std::cout << availableLettersArr[i] << " ";
        }
        std::cout << "\n";

    input:
        std::cin >> word;
        std::cout<<(wordContainsProvidedLettersOnly(word, availableLettersArr) ? "contains provided letters" : "incorrect letters")<<std::endl;
        std::cout<<(dictionaryContainsWord(word) ? "in dictionary" : "not in dictionary");
        if (wordContainsProvidedLettersOnly(word, availableLettersArr) && dictionaryContainsWord(word))
        {
            points += word.length();
            std::cout << word << " is a valid word! Your points so far are: " << points << "\n";
        }
        else
        {
            std::cout << "Invalid word. Try again with: ";
            printGivenLetters(availableLettersArr);
            goto input;
        }
    }

    std::cout << "Game over! Your total points are " << points << "." << std::endl
              << "Returning to menu.";
    openMainMenu();
}

void openMainMenu()
{
    printMenu();

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

int main()
{
    openMainMenu();
}