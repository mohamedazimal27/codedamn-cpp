/*
Calculator
Create a template class called Calculator that can perform basic arithmetic operations on two operands of any data type.
The class should have the following public methods:

T add(T num1, T num2): a method that returns the sum of num1 and num2.
T subtract(T num1, T num2): a method that returns the difference between num1 and num2.
T multiply(T num1, T num2): a method that returns the product of num1 and num2.
T divide(T num1, T num2): a method that returns the quotient of num1 and num2.
T modulus(T num1, T num2): a method that returns the remainder of num1 divided by num2.
The Calculator class should also have an exception handling mechanism that can detect and handle any attempts to divide by zero. 
If an attempt is made to divide by zero, the class should throw an exception with an appropriate error message.
Once you have defined the Calculator class, create an instance of the class and perform the following operations on it:

Calculate the sum, difference, product, quotient, and remainder of two integers (e.g. 10 and 5).
Calculate the sum, difference, product, quotient, and remainder of two doubles (e.g. 3.14 and 2.71).
Attempt to divide by zero and handle the resulting exception.

*/
#include <iostream>
using namespace std;


template <typename T>
class Calculator
{
public:
  T add(T num1, T num2)
  {
    return num1 + num2;
  }
  T subtract(T num1, T num2)
  {
    return abs(num1 - num2);
  }
  T multiply(T num1, T num2)
  {
    return num1 * num2;
  }
  T divide(T num1, T num2)
  {
    if (num2 == 0)
        throw "Divisible by zero not possible"
        return 0;
    return num1 / num2;
  }
  T modulus(T num1, T num2)
  {
    return num1 % num2;
  }
};

int main(){
    Calculator<int> calculator;
    int a,b;
    cin >> a;
    cin >> b;
    cout << "Sum: " << calculator.add(a,b) << endl;
    cout << "Subtract: " << calculator.subtract(a,b) << endl;
    cout << "Multiply: " << calculator.multiply(a,b) << endl;
    cout << "Divide: " << calculator.divide(a,b) << endl;
    cout << "Modulus: " << calculator.modulus(a,b) << endl;
    return 0;
}
