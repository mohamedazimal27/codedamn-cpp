/*In this assignment, you will write a C++ program that uses functions with parameters, arguments and return values, and scope.

Part 1: Function Parameters

Define a function named add that takes two integer arguments a and b.
Inside the add function, add a and b together and store the result in a local variable named sum.
Print the value of sum to the console.
Call the add function with two integer values of your choice.
Part 2: Function Arguments and Return Value

Define a function named power that takes two double arguments base and exponent.
Inside the power function, calculate the value of base raised to the power of exponent.
Return the result.
Call the power function with a base of 2.0 and an exponent of 3.0, and print the result to the console.
Part 3: Scope

Declare a variable named x of type int in the main function and initialize it to a value of your choice.
Define a function named print_x that takes no arguments.
Inside the print_x function, print the value of x to the console.
Call the print_x function from the main function.*/

#include <iostream>
#include <cmath>

void sum(int a, int b);
void power(float a, float b);
int main()
{
    sum(1,2);
    power(2.0,3.0);
    return 0;
}
void sum(int a, int b)
{
    std::cout << a + b << std::endl;
}
void power(float a, float b)
{
    std::cout << pow(a,b) << std::endl;
}