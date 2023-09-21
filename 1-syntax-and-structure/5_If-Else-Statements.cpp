/*
If-Else Statements
Write a program that takes two integers as input from the user and performs the following operations:

If both integers are positive, output their sum and product.
If both integers are negative, output their difference and quotient.
If one integer is positive and the other is negative, output their product and quotient.
If either of the integers is zero, output 0.
Output only the result (For Example, only sum and product for first case, or '0' without quotes for last case, on newline) and nothing else.
*/
// Lab Template


#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    int x,y;
    cin >> x;
    cin >> y;
    if (x > 0 && y > 0)
    {
        cout << x + y << endl;
        cout << x * y << endl;
    }
    else if( x < 0 && y < 0)
    {
        cout << x - y << endl;
        cout << x / y << endl;
    }
    else if(x > 0 && y < 0)
    {
        cout << x * y << endl;
        cout << x / y << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
