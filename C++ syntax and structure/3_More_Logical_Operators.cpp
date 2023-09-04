/*
More Logical Operators
Create a C++ program that prompts the user to enter two integers and stores them in separate variables.
Use logical operators to determine whether the first integer is greater than or equal to the second integer.
Use logical operators to determine whether the second integer is not equal to 0.
Use logical operators to determine whether both conditions in steps 2 and 3 are true.
Output the results of each comparison to the console and make sure to use endl after each output and display result of each comparison on new line.
Example Output: 1 1 1  Example Input: 10 5
In bool data type, 1 represents true and 0 represnts false, hence the output.
*/
// Lab Template

#include <iostream>

using namespace std;

int main() {
    cout << "Hello world" << endl;
    int a,b;
    cin >> a;
    cin >> b;
    int c;
    cout << (c = a >= b) << endl;
    cout << (c = b != 0) << endl;
    cout << (c = a >= b && b != 0) << endl;
    return 0;
}
