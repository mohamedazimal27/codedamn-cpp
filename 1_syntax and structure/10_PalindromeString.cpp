/*Write a function is_palindrome that takes a string as input and returns true if the string is a palindrome (i.e. reads the same backwards as forwards), and false otherwise. Your function should be case-insensitive, i.e. it should consider uppercase and lowercase letters to be the same.

Write a program that reads in a string from the user and uses the is_palindrome function to determine if the string is a palindrome or not. If the string is a palindrome, the program should output the message "The string is a palindrome". Otherwise, the program should output the message "The string is not a palindrome". ` Sample I/O: Input -> Radar Output -> true

Input -> Hello world Output ->false*/
#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string& input_string) {
    int left = 0;
    int right = input_string.length() - 1;

    // Check if the input string is a palindrome (ignoring case)
    while (left < right) {
        char leftChar = std::tolower(input_string[left]);
        char rightChar = std::tolower(input_string[right]);

        // Skip non-alphanumeric characters
        if (!isalnum(leftChar)) {
            left++;
        } else if (!isalnum(rightChar)) {
            right--;
        } else if (leftChar != rightChar) {
            return false;
        } else {
            left++;
            right--;
        }
    }

    return true;
}

int main() {
    std::string user_input;

    // Get input from the user
    std::getline(std::cin, user_input);

    // Check if the input is a palindrome using the is_palindrome function
    if (is_palindrome(user_input)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}
