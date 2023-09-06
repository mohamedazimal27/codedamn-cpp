#include<iostream>

// Inline function to add two integers
inline int adder(int a, int b) {
    return a + b;
}
int main() {
    int num1, num2;
    std::cin >> num1 >> num2;
    // Call the inline function to get the sum
    int sum = adder(num1, num2);
    // Output the result
    std::cout << sum << std::endl;
    return 0;
}
