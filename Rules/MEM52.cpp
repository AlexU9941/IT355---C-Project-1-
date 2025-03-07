#include <cstdlib>
#include <iostream>
#include <new>

/**
 * @brief Allocates memory for an array of integers and checks for memory allocation errors.
 * 
 * This function demonstrates how to handle memory allocation errors by throwing a `std::bad_alloc` exception 
 * when allocation fails. The exception is caught and handled in `main()`.
 */
void process() {
    int* ptr = static_cast<int*>(std::malloc(sizeof(int) * 100));
    
    if (ptr == nullptr) {
        throw std::bad_alloc();
    }

    std::free(ptr);
}

/**
 * @brief Entry point of the program.
 * 
 * Calls `process()` to demonstrate handling memory allocation errors using exceptions.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    try {
        process();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return 1;  
    }
    
    return 0;
}
