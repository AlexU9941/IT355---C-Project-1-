/**
 * @file ERR07.cpp
 * @brief Demonstrates recommendation ERR07 in C++.
 * 
 * This file uses std::stoi, a safe alternative to atoi.
 */

#include <iostream>
#include <string>
#include <exception>

/**
 * @brief Main function to convert a user-provided string to an integer safely.
 * 
 * This program prompts the user for a number, converts it using std::stoi, 
 * and handles potential errors such as invalid input and out-of-range values.
 * 
 * @return int Returns 0 on successful execution.
 */
int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    try {
        /**
         * @brief Converts the input string to an integer using std::stoi.
         * @throws std::invalid_argument If the input is not a valid number.
         * @throws std::out_of_range If the number exceeds the range of int.
         */
        int number = std::stoi(input);  
        std::cout << "You entered: " << number << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid input. Please enter a valid number.\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Number out of range.\n";
    }

    return 0;
}
