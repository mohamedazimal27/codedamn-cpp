#include <iostream>
#include <memory>

int main() {
    // Create a shared pointer to dynamically allocate an integer
    std::shared_ptr<int> myInt = std::make_shared<int>(42);

    // Print the value of the integer
    std::cout << "My integer is: " << *myInt << std::endl;

    // Create another shared pointer to the same integer
    std::shared_ptr<int> anotherInt = myInt;

    // Print the value of the integer through the other shared pointer
    std::cout << "My other integer is: " << *anotherInt << std::endl;

    // Reset the original shared pointer to null
    myInt.reset();

    // Print the value of the integer through the other shared pointer after resetting the original pointer
    std::cout << "My other integer is still: " << *anotherInt << std::endl;

    // The memory will be automatically cleaned up when the last shared pointer goes out of scope
    return 0;
}