#include <iostream>
#include <stdexcept>

// Function that may throw exceptions
/**
 * @brief Compares two numbers and prints the larger value to the console
 * 
 * @param x Number 1.
 * @param y Number 2.
 */
void findLarger(int x, int y) {
    if (x == y) {
        throw std::invalid_argument("Arguments are equal");
    }
    
    std::cout << x << " / " << y << " = " << x / y << std::endl;
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

