#include <iostream>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  int n = 5;
  int factorial_of_n = factorial(n);

  std::cout << "The factorial of " << n << " is " << factorial_of_n << std::endl;

  return 0;
}