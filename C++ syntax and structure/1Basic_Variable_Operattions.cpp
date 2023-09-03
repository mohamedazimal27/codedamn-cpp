#include <iostream>

int main()
{
    int x;
    std::cin >> x;
    int y;
    std::cin >> y;
    int sum = x + y;
    int difference = x - y;
    int product = x * y;
    int quotient = x / y;
    int remainder = x % y; 
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << sum << std::endl;
    std::cout << difference << std::endl;
    std::cout << product << std::endl;
    std::cout << quotient << std::endl;
    std::cout << remainder << std::endl;
    return 0;
}