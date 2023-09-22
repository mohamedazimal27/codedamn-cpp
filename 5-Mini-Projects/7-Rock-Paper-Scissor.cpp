/*
Create a program that allows the user to play a game of Rock, Paper, Scissors against the computer.
The program should prompt the user to input their choice of Rock, Paper, or Scissors, generate a random
choice for the computer, and determine the winner based on the rules of the game.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // Seed the random number generator with the current time
    srand(time(0));

    // Array of choices for the computer
    string choices[] = {"Rock", "Paper", "Scissors"};

    // Get user's choice
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice (Rock, Paper, or Scissors): ";
    string userChoice;
    cin >> userChoice;

    // Generate a random choice for the computer
    int randomIndex = rand() % 3; // 0 for Rock, 1 for Paper, 2 for Scissors
    string computerChoice = choices[randomIndex];

    // Display the choices made by the user and computer
    cout << "You chose: " << userChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;

    // Determine the winner
    if (userChoice == computerChoice)
    {
        cout << "It's a tie!" << endl;
    }
    else if (
        (userChoice == "Rock" && computerChoice == "Scissors") ||
        (userChoice == "Paper" && computerChoice == "Rock") ||
        (userChoice == "Scissors" && computerChoice == "Paper"))
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
