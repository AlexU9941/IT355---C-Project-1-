/**
 * @file ERR51.cpp
 * @brief Demonstrates rule ERR51 in C++.
 * 
 * This program defines and uses two custom exception classes, `PositiveError`
 * and `NegativeError`, to handle positive and negative number errors.
 * The `processNumber` function processes an integer and throws an exception
 * if the number is not zero.
 */

#include <iostream>
#include <stdexcept>

/**
 * @class PositiveError
 * @brief Exception thrown when a positive number is encountered.
 */
class PositiveError : public std::exception {
public:
    /**
     * @brief Provides an error message for positive number exceptions.
     * @return A C-style string describing the error.
     */
    const char* what() const noexcept override {
        return "Positive number error occurred!";
    }
};

/**
 * @class NegativeError
 * @brief Exception thrown when a negative number is encountered.
 */
class NegativeError : public std::exception {
public:
    /**
     * @brief Provides an error message for negative number exceptions.
     * @return A C-style string describing the error.
     */
    const char* what() const noexcept override {
        return "Negative number error occurred!";
    }
};

/**
 * @brief Processes a number and throws exceptions based on its value.
 * 
 * @param num The integer to process.
 * @throws PositiveError If num is positive.
 * @throws NegativeError If num is negative.
 */
void processNumber(int num) {
    if (num == 0) {
        std::cout << "Success: Zero passed in.\n";
    } else if (num > 0) {
        throw PositiveError();
    } else {
        throw NegativeError();
    }
}

int main() {
    int num;

    // Example inputs
    num = 0;
    try {
        processNumber(num);
    } catch (const PositiveError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const NegativeError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    num = 5;
    try {
        processNumber(num);
    } catch (const PositiveError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const NegativeError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    num = -3;
    try {
        processNumber(num);
    } catch (const PositiveError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const NegativeError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    return 0;
}
