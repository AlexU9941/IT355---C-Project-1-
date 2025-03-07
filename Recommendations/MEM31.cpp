#include <cstdlib>
#include <iostream>

/**
 * @brief Allocates memory dynamically and frees it when no longer needed.
 * 
 * This function demonstrates proper memory management by allocating memory for an 
 * integer and ensuring it is freed when the memory is no longer required.
 */
void process() {
    // Dynamically allocate memory for an integer
    int* ptr = (int*)malloc(sizeof(int));

    // Check if memory allocation was successful
    if (ptr == nullptr) {
        std::cerr << "Memory allocation failed\n";
        return;
    }

    // Free dynamically allocated memory when no longer needed
    free(ptr);
}

/**
 * @brief Entry point of the program.
 * 
 * Calls `process()` to demonstrate proper memory allocation and deallocation.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
