/*
Understanding Logical Operators in C++
In this assignment, you will learn about logical operators in C++ and how they are used to combine and evaluate logical expressions.

Part 1: Logical Operators

Declare two boolean variables named a and b.
Initialize a to true and b to false.
Declare a third boolean variable named result.
Initialize result to the result of the && operator applied to a and b.
Print the value of result to the console.
Initialize result to the result of the || operator applied to a and b.
Print the value of result to the console.
Initialize result to the result of the ! operator applied to a.
Print the value of result to the console. Part 2: Short-Circuit Evaluation
Declare a boolean variable named c and initialize it to true.
Declare an integer variable named x and initialize it to 0.
nitialize x to the result of the expression (c || (x = 42)).
Print the value of x to the console.
*/

#include <iostream>
int main()
{
    bool a,b;
    a = true;
    b = false;
    bool result;
    result = a&&b;
    std::cout << "a && b ="<< result << std::endl;
    result = a || b;
    std::cout << "a || b ="<< result << std::endl; 
    result = !a;
    std::cout << "!a ="<< result << std::endl;
    bool c = true;
    int x = 0;
    //x = (c || (x =42));
    std::cout << x << std::endl;
    return 0;
}