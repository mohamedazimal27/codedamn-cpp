/*
In this assignment, you will write a C++ program that uses loops to perform simple repetitive tasks.

Part 1: For Loop

Declare an integer variable named n.
Initialize n to a value of your choice.
Write a for loop that counts from 1 to n, printing each number to the console. 
Part 2: While Loop
Declare an integer variable named sum.
Initialize sum to 0.
Write a while loop that adds the numbers from 1 to 10 to sum.
Print the value of sum to the console. 
Part 3: Do-While Loop
Declare an integer variable named x.
Initialize x to a value of your choice.
Write a do-while loop that repeatedly prompts the user to enter a number until the user enters a number that is greater than or equal to x.
Print the value entered by the user to the console.
*/
#include <iostream>
using namespace std;

int main(){
    //Part 1 - For loop
    int n;
    n = 10;
    for (int i = 1; i < n; i++)
    {
        cout << i << endl;
    }
    //Part 2 - While loop
    int sum = 0;
    while (sum < 10)
    {
        sum += 1;
        cout << sum << endl;
    }
    //Part 3 - Do while
    int input;
    int x;
    do
    {
        x = 10;
        cout << "Enter a number: "; 
        cin >> input;
    }while(input <= x);
    return 0;
}
