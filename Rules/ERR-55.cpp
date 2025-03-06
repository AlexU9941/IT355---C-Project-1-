/**
 * @file ERR-55.cpp
 * @brief Demonstrates rule ERR-55 in C++.
 * 
 * This file contains a function that is explicitly marked as noexcept, 
 * indicating that it does not throw exceptions.
 */

#include <iostream>
#include <stdexcept>

/**
 * @brief A function that does not throw exceptions.
 * 
 * This function is marked with noexcept, guaranteeing that it will not 
 * propagate exceptions.
 */
void safeFunction() noexcept {
    std::cout << "safeFunction() executing safely.\n";
}

int main() {
    safeFunction();

    return 0;
}
