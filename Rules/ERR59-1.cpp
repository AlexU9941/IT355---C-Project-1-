/**
 * @file ERR59-1.cpp
 * @brief Demonstrates rule ERR-59 in C++. Main file.
 * 
 * This file demonstrates calling a function from a shared library, handling errors 
 * from the return code, and displaying an appropriate error message.
 */

#include <iostream>
#include "ERR59-2.h" ///< Header file for the shared library function

/**
 * @brief Main function of the program.
 * 
 * This function calls a function from a shared library and handles potential errors 
 * by printing an error message if the function fails.
 * 
 * @return 0 if the operation is successful, 1 if an error occurs.
 */
int main() {
    std::string errorMsg;
    
    // Call the function from the shared library
    if (riskyFunction(errorMsg) == ErrorCode::FAILURE) {
        std::cerr << "Error: " << errorMsg << std::endl;
        return 1;
    }

    std::cout << "Operation succeeded!" << std::endl;
    return 0;
}
