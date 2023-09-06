/*Problem Statement:

Write two functions named area() that compute the area of a rectangle and a circle, respectively. 
The area() function for the rectangle should take two integer arguments length and width and return the area of the rectangle, which is length x width. 
The area() function for the circle should take a single integer argument radius and return the area of the circle, which is pi x radius^2. 
Write a program that reads in the shape and dimensions from the user and outputs the area.

Input Format:

The input consists of a single character c or r on the first line, followed by two integers a and b (if c is entered, b is ignored) separated by a space on the second line.

Output Format:

The output consists of a single floating-point value, the area of the rectangle or circle depending on the input.

Sample Input 1: r 4 5 Sample Output 1: 20 Note:

The value of pi can be approximated as 3.14159. The two area() functions should have the same name but different argument lists (i.e., they should be overloaded functions).*/

#include <iostream>


int area(int length, int width);
float area(int radius);

int main()
{
    std::string input;
    std::cin >> input;
    if (input == "r")
    {
        int a,b;
        std::cin >> a;
        std::cin >> b;
        std::cout << area(a,b) <<std::endl;
    }
    else if (input == "c")
    {
        int a;
        std::cin >> a;
        std::cout << area(a) <<std::endl;
    }
    else
    {
        std::cout << std::endl;
    }
    return 0;
}

int area(int length, int width)
{
    return length * width;
}
float area(int radius)
{
    return 3.14159 * radius * radius;
}