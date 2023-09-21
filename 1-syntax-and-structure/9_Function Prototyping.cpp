/*In this assignment, you will write a C++ program that uses function prototyping to define and call functions.

Part 1: Function Prototyping
Define a function named cube that takes an integer argument n and returns the cube of n.
Declare the cube function prototype at the top of the file.
In the main function, prompt the user to enter an integer value and store it in a variable named x.
Call the cube function with x as the argument and print the result to the console. 
Part 2: Multiple Function Prototypes
Define two functions named add and subtract that take two integer arguments a and b and return the sum and difference of a and b, respectively.
Declare the add and subtract function prototypes at the top of the file.
In the main function, prompt the user to enter two integer values and store them in variables named x and y.
Call the add function with x and y as the arguments and print the result to the 5. console.
Call the subtract function with x and y as the arguments and print the result to the console.*/

#include<iostream>

int cube(int n);
void sum(int a, int b);
void difference(int a, int b);

int main()
{
    int x;
    std::cin >> x;
    std::cout << cube(x) << std::endl;
    int a,b;
    std::cin >> a >> b ;
    sum(a,b);
    difference(a,b);
    return 0;
}

int cube(int n)
{
    int cube = n * n * n;
    return cube;
}
void sum(int a,int b)
{
    std::cout << a + b << std::endl;
}
void difference(int a,int b)
{
    std::cout << a - b << std::endl;
}