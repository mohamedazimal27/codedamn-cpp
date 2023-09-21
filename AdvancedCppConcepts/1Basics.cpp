#include <iostream>
using namespace std;

int main() {
  try {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if(num2 == 0) {
      throw "Division by zero error";
    }

    double result = static_cast<double>(num1) / num2;
    cout << "Result: " << result << endl;
  }
  catch(const char* error) {
    cerr << "Error: " << error << endl;
  }

  return 0;
}