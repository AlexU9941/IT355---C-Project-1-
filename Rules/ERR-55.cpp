#include <iostream>
#include <stdexcept>

// Function marked noexcept does not throw exceptions
void safeFunction() noexcept {
    std::cout << "safeFunction() executing safely.\n";
}

int main() {
    safeFunction();

    return 0;
}
