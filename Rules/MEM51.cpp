#include <memory>

/**
 * @brief Demonstrates proper memory management using smart pointers.
 * 
 * This function allocates an integer using `std::unique_ptr`, ensuring automatic 
 * deallocation when the pointer goes out of scope.
 */
void process() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42); // Memory is automatically managed
}

/**
 * @brief Entry point of the program.
 * 
 * Calls `process()` to demonstrate safe resource management.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main() {
    process();
    return 0;
}
