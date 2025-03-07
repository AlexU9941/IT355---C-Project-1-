#include <new>
#include <iostream>

/**
 * @brief Allocates aligned memory and constructs an integer using placement new.
 * 
 */
void process() {
    alignas(int) unsigned char buffer[sizeof(int)]; 
    int* obj = new (buffer) int;
    std::cout << "Value: " << *obj << "\n";
    
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
