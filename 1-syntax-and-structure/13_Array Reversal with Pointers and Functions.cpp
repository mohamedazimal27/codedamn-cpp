/*
Write a program that reads in an array of integers from the user and reverses it using a function that takes an integer array pointer and its size 
as arguments. The program should print the original and reversed arrays to the console.

Example output:

Enter the size of the array: 5 Enter the elements of the array: 1 2 3 4 5 Original array: 1 2 3 4 5 Reversed array: 5 4 3 2 1

To complete this assignment, you'll need to use pointers to access and modify the elements in the array, and a function to reverse the order of the elements.

Here are the steps to complete the assignment:

Prompt the user to enter the size of the array using cin.
Declare an integer array with the given size.
Use a loop to read in the elements of the array using cin.
Print the original array to the console using a loop and pointer arithmetic.
Declare a function that takes an integer array pointer and its size as arguments.
Use a loop in the function to reverse the order of the elements in the array using pointer arithmetic.
Call the function with the integer array pointer and its size as arguments.
Print the reversed array to the console using a loop and pointer arithmetic.
*/

#include <iostream>
using namespace std;

void ReverseArray(int *ptr, int size)
{
    cout << "Reversed Array:";
    for(int i = size - 1; i >= 0; i--)
    {
        cout << " " << *(ptr + i );
    }
    cout << endl;
}

int main(){
    int arrSize;
    cout << "Enter the size of the array: "; 
    cin >> arrSize;
    int arrInt[arrSize];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arrInt[i];
    }
    cout << "Original Array:";
    for(int i = 0; i < arrSize; i++)
    {
        cout << " " << arrInt[i];
    }
    cout << endl;
    int *ptrArr = arrInt;
    ReverseArray(ptrArr, arrSize);
    return 0;
}
