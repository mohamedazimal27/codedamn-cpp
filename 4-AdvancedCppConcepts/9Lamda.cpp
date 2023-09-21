/*
In this code, a lambda expression is used to define custom sorting and filtering functions for a vector of integers. 
The std::sort function takes a lambda expression that defines the comparison operator used to sort the vector in descending order. 
The std::remove_if function takes a lambda expression that defines the predicate used to filter out odd numbers from the vector. 
By using lambda expressions, we can define these custom functions inline and avoid having to define separate functions outside of our main function.
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {4, 2, 7, 1, 9, 5, 8, 3, 6};

    // Sort the vector in descending order using a lambda expression
    std::sort(numbers.begin(), numbers.end(), [](int a, int b)
              { return a > b; });

    // Print the sorted vector
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Filter the vector to only include even numbers using a lambda expression
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int num)
                                 { return num % 2 == 1; }),
                  numbers.end());

    // Print the filtered vector
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}