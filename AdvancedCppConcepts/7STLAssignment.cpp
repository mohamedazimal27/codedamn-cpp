/*
Create a program that uses the STL vector container to perform the following tasks:

Create an empty vector of integers.
Ask the user to input a series of integers (terminated by a non-integer input).
Add each integer to the vector.
Print the contents of the vector to the console.
Sort the vector in ascending order.
Print the sorted vector to the console.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector <int> var;
    int num;
    do
    {
        std::cin >> num; 
        var.push_back(num);
    } while (num > 0);
    for (auto i : var)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    //sort vectors
    std::sort(var.begin(), var.end());
    //print in ascending order
    for(auto i: var)
    {
        std::cout << i << " ";
    }
    return 0;
}