#include <iostream>
#include <stdexcept>

// Global object with a constructor that may throw
struct GlobalInitializer {
    GlobalInitializer() {
        throw std::runtime_error("Global object initialization failed");
    }
};

GlobalInitializer* globalInstance = nullptr;

// Initialization function that handles exceptions before main()
void safeInitialization() {
    try {
        globalInstance = new GlobalInitializer();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught before main(): " << e.what() << std::endl;
        std::exit(EXIT_FAILURE); // Ensure program terminates safely
    }
}

// Execute safe initialization before main()
struct RunBeforeMain {
    RunBeforeMain() { safeInitialization(); }
};

// This object ensures safeInitialization runs before main()
RunBeforeMain initializer;

int main() {
    std::cout << "Main function executing normally." << std::endl;
    return 0;
}
