/*
In this assignment, you will write a C++ program that uses switch statements to perform conditional logic based on a user input.

Part 1: User Input

Prompt the user to enter a number between 1 and 5.
Read the user input into an integer variable named choice. Part 2: Conditional Logic
Write a switch statement that checks the value of choice.
If choice is 1, print the message "You chose option 1" to the console.
If choice is 2, print the message "You chose option 2" to the console.
If choice is 3, print the message "You chose option 3" to the console.
If choice is 4, print the message "You chose option 4" to the console.
If choice is 5, print the message "You chose option 5" to the console.
If choice is not between 1 and 5, print the message "Invalid choice" to the console.
*/
#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number between 1 and 5" << endl;
    int userInt;
    cin >> userInt;
    switch (userInt)
    {
    case 1:
        cout << "You chose option 1" << endl;
        break;
    case 2:
        cout << "You chose option 2" << endl;
        break;
    case 3:
        cout << "You chose option 3" << endl;
        break;
    case 4:
        cout << "You chose option 4" << endl;
        break;
    case 5:
        cout << "You chose option 5" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
    return 0;
}
