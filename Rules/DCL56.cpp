/**
 * @file example.cpp
 * @brief Example file demonstrating a factorial function with exception handling.
 *
 * This file contains an example of how to implement a factorial function that throws
 * an exception for invalid input, fulfilling the DCL56-CPP rule by ensuring that
 * all exceptions are properly documented and handled.
 */

#include <stdexcept>
#include <iostream>

/**
 * @brief Computes the factorial of a non-negative integer.
 *
 * This function computes the factorial of a given non-negative integer. If the input
 * If the input is negative, it throws a std::domain_error exception.
 *
 * @param i The integer for which to compute the factorial.
 * @return The factorial of the input integer.
 * @throws std::domain_error if the input integer is negative.
 */
int fact(int i) noexcept(false){
    if (i < 0){
        //meaning negative factorials are defined
        throw std::domain_error("i must be >= 0");
    }

    static int cache[17];
    if (i < (sizeof(cache) / sizeof(int))){
        if (0 == cache[i]){
            cache[i] = i > 0 ? i *fact(i-1) : 1;  
        }
        return cache[i]; 
    }
    return i > 0 ? i * fact(i-1) : 1; 
}


/**
 * @brief Main function.
 *
 * This is the entry point of the program. It calls the fact function with a valid input.
 * Catches any exceptions thrown. 
 * Then prints the result to the console.
 * @return 0 on success.
 */
int main(){
    try{
        std::cout << "7! = " << fact(7) << "\n";
    } catch (const std::exception& e){
        std::cerr << e.what() << "\n"; 
    }
}
