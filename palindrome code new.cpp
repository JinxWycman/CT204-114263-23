#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

// Function to check if a number is a palindrome
bool isNumberPalindrome(int number) {
    int original = number;
    int reversed = 0;

    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    return original == reversed;
}

// Function to check if a string is a palindrome
bool isWordPalindrome(const std::string& word) {
    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    // Test the number palindrome function
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isNumberPalindrome(number)) {
        std::cout << number << " is a palindrome number." << std::endl;
    } else {
        std::cout << number << " is not a palindrome number." << std::endl;
    }

    // Test the word palindrome function
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;

    // Convert to lowercase to ensure case insensitivity
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    if (isWordPalindrome(word)) {
        std::cout << word << " is a palindrome word." << std::endl;
    } else {
        std::cout << word << " is not a palindrome word." << std::endl;
    }

    return 0;
}