// MEM50-CPP: Do not access freed memory

#include <cstdlib>

/**
 * @brief Allocates and deallocates memory safely to prevent use-after-free errors.
 * 
 * This function demonstrates proper dynamic memory management by ensuring 
 * that a pointer is set to `nullptr` after freeing to prevent accidental access.
 */
void process() {
    // Allocate memory for a single integer
    int* ptr = static_cast<int*>(std::malloc(sizeof(int)));
    
    // Check if allocation was successful
    if (ptr == nullptr) {
        return;
    }

    // Free allocated memory
    std::free(ptr);
    
    // Prevent use-after-free by nullifying the pointer
    ptr = nullptr;
}

/**
 * @brief Entry point of the program.
 * 
 * Calls `process()` to demonstrate safe memory management practices.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
