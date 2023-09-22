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
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

int main()
{
    // Create an array of words
    std::vector<std::string> words = {"apple", "orange", "cat", "dog", "animal", "love", "money", "care", "gold", "paradise"};

    // Seed the random number generator
    std::mt19937 gen(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, words.size() - 1);

    // Choose a random word from the array
    std::string selectedWord = words[distribution(gen)];

    int maxIncorrectGuesses = 6; // Set a maximum number of incorrect guesses
    int incorrectGuesses = 0;

    std::vector<char> guessedLetters; // Keep track of guessed letters

    std::cout << "Welcome to Hangman!" << std::endl;

    while (incorrectGuesses < maxIncorrectGuesses)
    {
        std::cout << "Guess the word: ";

        // Display the word with underscores for hidden letters
        for (char letter : selectedWord)
        {
            if (std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end())
            {
                std::cout << letter << " ";
            }
            else
            {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;

        // Check if the user has won
        if (std::all_of(selectedWord.begin(), selectedWord.end(),
                        [&guessedLetters](char letter)
                        {
                            return std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
                        }))
        {
            std::cout << "Congratulations! You guessed the word: " << selectedWord << std::endl;
            break;
        }

        // Take user input
        char guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        // Check if the letter has already been guessed
        if (std::find(guessedLetters.begin(), guessedLetters.end(), guess) != guessedLetters.end())
        {
            std::cout << "You've already guessed that letter." << std::endl;
            continue;
        }

        // Add the guessed letter to the list
        guessedLetters.push_back(guess);

        // Check if the guessed letter is in the word
        if (selectedWord.find(guess) == std::string::npos)
        {
            std::cout << "Incorrect guess!" << std::endl;
            incorrectGuesses++;
        }
    }

    // Check if the user has run out of attempts
    if (incorrectGuesses >= maxIncorrectGuesses)
    {
        std::cout << "You ran out of attempts. The correct word was: " << selectedWord << std::endl;
    }

    return 0;
}
