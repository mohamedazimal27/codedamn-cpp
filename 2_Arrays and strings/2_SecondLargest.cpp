/*Write a program that finds the second largest element in an array of integers. The program should first ask the user how many integers they want to enter, and then read in that many integers. If the array has less than two elements, the program should output 0.

Sample Input: 5 10 20 5 30 25 

Sample Output(Valid):  25

Sample Output(Invalid): ` 0*/

#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int array[num];
    for(int i=0; i < num; i++)
    {
        std::cin >> array[i];
    }
    return 0;
}