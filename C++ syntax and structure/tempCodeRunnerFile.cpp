#include <iostream>
int main()
{
    bool a,b;
    a = true;
    b = false;
    bool result;
    result = a&&b;
    std::cout << "a && b ="<< result << std::endl;
    result = a || b;
    std::cout << "a || b ="<< result << std::endl; 
    result = !a;
    std::cout << "!a ="<< result << std::endl;
    bool c = true;
    int x = 0;
    //x = (c || (x =42));
    std::cout << x << std::endl;
    return 0;
}