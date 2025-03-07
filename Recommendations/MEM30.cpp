#include <cstdlib>
#include <iostream>

/**
 * @brief Allocates memory dynamically, frees it, and nullifies the pointer to prevent use-after-free errors.
 * 
 */
void process() {

    int* ptr = (int*)std::malloc(sizeof(int));

    if (ptr == nullptr) {
        std::cerr << "Memory allocation failed\n";
        return;
    }

    std::free(ptr);
    ptr = nullptr;
}

/**
 * @brief main.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
