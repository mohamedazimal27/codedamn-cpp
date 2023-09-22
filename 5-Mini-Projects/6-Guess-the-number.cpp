/*
Guess the Number
Create a program that generates a random number between 1 and 100, and prompts the user to guess the number.
The program should provide feedback to the user after each guess, telling them whether their guess was too high or too low.
The program should continue prompting the user until they correctly guess the number.
*/

#include <iostream>
#include <random>
#include <ctime>

int main()
{
    std::cout << "Welcome to Guess-the-number Game" << std::endl;

    // Seed the random number generator
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, 100);
    int guessed_num = distribution(gen);

    // Get num from user
    int num;
    // Game Starts
    bool gameNotFinished = true;
    while (gameNotFinished)
    {
        do
        {
            std::cout << "Enter the number(1-100): ";
            std::cin >> num;
        } while (num < 0 || num > 100);

        if (guessed_num < num)
            std::cout << "your option is greater than guess number" << std::endl;
        else if (guessed_num > num )
            std::cout << "your option is lesser than guess number" << std::endl;
        else
        {
            std::cout << "Your Guess Number is Correct" << std::endl;
            gameNotFinished = false;
        }
    }
}