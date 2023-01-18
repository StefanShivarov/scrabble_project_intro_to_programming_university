#include <iostream>

void printMenu()
{
    std::cout << "Welcome to Scrabble!\n-------------------------------\nMain Menu\n-------------------------------\n";
    std::cout << "1. New game\n2. Settings\n3. Add word to dictionary\n4. Exit\n";
    std::cout << "Choose an activity: ";
}

void openMainMenu(){
    printMenu();
}

int main(){

    openMainMenu();
}