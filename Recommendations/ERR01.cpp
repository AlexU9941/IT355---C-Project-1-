#include <cstdio>
#include <iostream>

int main() {
    FILE *file = fopen("example.txt", "w"); // Open file for writing
    
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }
    
    // Attempt to write to the file
    if (fputs("Some Data.\n", file) == EOF) {
        std::cerr << "Error writing to file!\n";
    }
    
    // Check for errors using ferror()
    if (ferror(file)) {
        std::cerr << "I/O error occurred!\n";
    }
    
    // Close the file
    if (fclose(file) != 0) {
        std::cerr << "Error closing file!\n";
    }
    
    return 0;
}