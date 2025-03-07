#include <cstdlib>
#include <iostream>

/**
 * @brief Allocates and deallocates memory safely.
 * 
 */
void process() {

    int* ptr = (int*)malloc(sizeof(int));
    if (ptr == nullptr) {
        std::cerr << "Memory allocation failed\n";
        return;
    }

    free(ptr);
}

/**
 * @brief Entry point of the program.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
