/**
 * @file ERR-56.cpp
 * @brief Demonstrates rule ERR-56 in C++.
 * 
 * This file defines a custom class `PositiveVector` which only allows adding 
 * non-negative integers to a vector. It handles invalid inputs by throwing 
 * exceptions and provides a method to print the contents of the vector.
 */

#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * @class PositiveVector
 * @brief A class that only accepts non-negative integers in its vector.
 * 
 * This class provides methods to add values to a vector and print its contents. 
 * If an attempt is made to add a negative value, an exception is thrown.
 */
class PositiveVector {
public:
    /**
     * @brief Adds a non-negative value to the vector.
     * 
     * If the value is negative, throws an std::invalid_argument exception.
     * 
     * @param value The integer to add to the vector.
     * @throws std::invalid_argument if the value is negative.
     */
    void addValue(int value) {
        if (value < 0) {
            throw std::invalid_argument("Cannot add a negative number.");
        }
        data.push_back(value);
    }

    /**
     * @brief Prints the contents of the vector.
     */
    void print() const {
        std::cout << "Vector contents: ";
        for (int v : data) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> data;
};

int main() {
    PositiveVector vec;

    try {
        vec.addValue(10);
        vec.print();
        vec.addValue(20);
        vec.print();
        vec.addValue(-5); // Throws exception
        vec.print();
        vec.addValue(30);  // This won't be reached if an exception occurs
        vec.print();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    vec.print();

    return 0;
}
