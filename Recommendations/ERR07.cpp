#include <iostream>
#include <string>
#include <exception>

int main() {
    std::string input;
    std::cout << "Enter a number: ";
    std::cin >> input;

    try {
        int number = std::stoi(input);  // Safe alternative to atoi
        std::cout << "You entered: " << number << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Invalid input. Please enter a valid number.\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: Number out of range.\n";
    }

    return 0;
}
