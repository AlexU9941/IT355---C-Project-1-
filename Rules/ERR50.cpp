/**
 * @file ERR50.cpp
 * @brief Demonstrates Rule ERR-50 in C++.
 * 
 * This program asks for two numbers from the user and prints out which is larger.
 * Program will throw an error if the two numbers are the same.
 *
 */

#include <iostream>
#include <stdexcept>

/**
 * @brief Determines and prints the larger of two integers.
 * 
 * @param x First integer.
 * @param y Second integer.
 * 
 * @throws std::invalid_argument if the numbers are equal.
 */
void findLarger(int x, int y) {
    if (x == y) {
        throw std::invalid_argument("Arguments are equal");
    }
    else if (x > y) {
        std::cout << x << " is larger." << std::endl;
    }
    else {
        std::cout << y << " is larger." << std::endl;
    }
}

int main() {
    int x, y;
    while (true) {
        try {
            std::cout << "Enter a number: ";
            std::cin >> x;
            std::cout << "Enter another number: ";
            std::cin >> y;

            findLarger(x, y);  // If valid, break out of loop
            break;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << ". Please enter different values.\n";
        }
    }

    std::cout << "Program completed successfully.\n";
    return 0;
}
