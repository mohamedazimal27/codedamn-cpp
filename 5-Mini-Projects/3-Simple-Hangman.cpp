/*
Hangman
Create a console application that simulates a game of hangman.

The program should choose a random word from a list of words and prompt the user to guess letters one at a time.
If the user correctly guesses a letter, the program should reveal the location of that letter in the word.
If the user makes too many incorrect guesses, the game should end and the correct word should be revealed.
Use a string container to store the selected word and the user's guesses.
*/
/*
1. Lets take a array of strings with 10 words in it
2. Choose one word randomly
*/

#include <iostream>
#include <random>

int main()
{
    // Create a array of string of words
    std::string arrStr[] = {"Apple", "Orange", "Cat", "Dog", "Animal", "Love", "Money", "Care", "Gold", "Paradise"};

    // Seed the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range [0, 10]
    std::uniform_int_distribution<int> distribution(0, arrStr->length());

    // Generate a random number
    int random_number = distribution(gen);
    std::string guessWord = arrStr[random_number];

    // Display dashes w.r.t words
    for (int i = 0; i < guessWord.length(); i++)
    {
        std::cout << "_ ";
    }
    std::cout << std::endl;

    // Take input from user
    char userChar;
    bool notFound = false;
    bool idxfound[guessWord.length()] = {false};
    char guessedChar[guessWord.length()];
    for (int i = 0; i < guessWord.length(); i++)
    {
        guessedChar[i] = {'_'};
    }

    while (!notFound)
    {
        std::cout << "Enter a char: ";
        std::cin >> userChar;
        notFound = true;

        // Replace the dash with matching user input
        for (int i = 0; i < guessWord.length(); i++)
        {
            if (guessWord[i] == userChar)
            {
                guessedChar[i] = userChar;
                std::cout << guessedChar[i] << " ";
                idxfound[i] = true;
            }
            else
                std::cout << guessedChar[i] << " ";
        }
        std::cout << std::endl;
        // Check user input present in guess word
        // Check each element in the array
        for (int i = 0; i < guessWord.length(); i++)
        {
            if (!idxfound[i])
            {
                notFound = false; // Found a false element, set allTrue to false
                break;            // No need to continue checking, we already know not all elements are true
            }
        }
    }
    return 0;
}