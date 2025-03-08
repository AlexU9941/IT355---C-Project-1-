/**
 * @file ERR01.cpp
 * @brief Demonstrates recommendation ERR01 in C++.
 * 
 * This file uses ferror() on a file stream to report a errors.
 */

#include <cstdio>
#include <iostream>

/**
 * @brief Main function to demonstrate safe file handling in C.
 * 
 * This program opens a file for writing, writes data to it, checks for errors, 
 * and then properly closes the file, handling potential failures at each step.
 * 
 * @return int Returns 0 on successful execution, 1 if file operations fail.
 */
int main() {
    /**
     * @brief Opens a file named "example.txt" in write mode.
     * @details fopen() is used to open the file. If it fails, an error message is displayed.
     */
    FILE *file = fopen("example.txt", "w"); // Open file for writing
    
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }
    
    /**
     * @brief Writes data to the file using fputs().
     * @details If fputs() fails (returns EOF), an error message is displayed.
     */
    if (fputs("Some Data.\n", file) == EOF) {
        std::cerr << "Error writing to file!\n";
    }
    
    /**
     * @brief Checks for I/O errors using ferror().
     * @details If an error is detected, an appropriate message is displayed.
     */
    if (ferror(file)) {
        std::cerr << "I/O error occurred!\n";
    }
    
    /**
     * @brief Closes the file using fclose().
     * @details If fclose() fails (returns non-zero), an error message is displayed.
     */
    if (fclose(file) != 0) {
        std::cerr << "Error closing file!\n";
    }
    
    return 0;
}
