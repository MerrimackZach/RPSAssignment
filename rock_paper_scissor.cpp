#include <iostream>
#include <cstdlib>
#include <ctime>

//Get the user input for R,S,P 
char getUserChoice() {
    char choice;
    std::cout << "Enter (r)ock, (s)cissors, or (p)aper: ";
    std::cin >> choice; // Reads the input and stores it in choice
    return choice;
}
// Computer Choice (randNum)
char getComputerChoice() {
    srand(time(0)); // Seed for random number generation
    int randNum = rand() % 3; // Generates a random number between 0-2, (0 = r, 1 = s, 2 = p)
    if (randNum == 0)
        return 'r';
    else if (randNum == 1)
        return 's';
    else
        return 'p';
}
// Actual game 
void playRPS() {
    char userChoice, compChoice;
    while (true) {
        userChoice = getUserChoice();
        if (userChoice != 'r' && userChoice != 's' && userChoice != 'p') {
            std::cout << "Only 'r', 's', or 'p' are valid inputs! Please try again." << std::endl;
        } else {
            break;
        }
    }
// results fxn, r loses p, r beats s, s beats p, s loses r, p beats r, p loses c, use ||. 
    compChoice = getComputerChoice();
    if (userChoice == compChoice) {
        std::cout << "It's a tie, double or nothing?" << std::endl;
    } else if ((userChoice == 'r' && compChoice == 'p') ||
               (userChoice == 'p' && compChoice == 's') ||
               (userChoice == 's' && compChoice == 'r')) {
        std::cout << "Sorry, you lost as I had " << compChoice << std::endl;
    } else { // If i win congrats message
        std::cout << "Congrats, you won as I had " << compChoice << std::endl;
    }
}

int main() {
    playRPS();
    return 0;
}
