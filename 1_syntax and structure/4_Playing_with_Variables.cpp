/*
In this assignment, you will learn about variables in C++ and how they are used to store and manipulate data.

Part 1: Variable Declaration and Initialization

Declare a variable named myInt of type int.
Initialize myInt to a value of your choice.
Declare a variable named myDouble of type double.
Initialize myDouble to a value of your choice. Part 2: Basic Variable Operations
Declare a variable named sum of type int.
Assign sum the value of the sum of myInt and myDouble, after converting myDouble to an int using the cast operator.
Print the value of sum to the console. Part 3: User Input and Variable Manipulation
Prompt the user to enter an integer value.
Declare a variable named userInt of type int.
Read the integer value entered by the user from the console and store it in userInt.
Declare a variable named product of type int.
Assign product the value of the product of myInt and userInt.
Print the value of product to the console. Part 4: Variable Scope and Lifetime
Declare a variable named myString of type std::string inside a block or scope of your choice.
Assign myString a value of your choice.
Print the value of myString to the console inside the same block or scope where it was declared.
Attempt to print the value of myString to the console outside the block or scope where it was declared. Observe the error message that is produced.
*/

#include <iostream>
using namespace std;

int main(){
    //Part 1: Variable Declaration and Initialization
    int myInt;
    myInt = 1;
    double myDouble;
    myDouble = 0.00001;
    //Part 2: Basic Variable Operations
    int sum;
    sum = myInt + (int)myDouble;
    cout << sum << endl;
    //Part 3: User Input and Variable Manipulation
    int userInt;
    cin >> userInt;
    int product;
    product = userInt * myInt;
    //Part 4: Variable Scope and Lifetime
    string myString;
    myString = "myName";
    cout << myString << endl;
    return 0;
}
