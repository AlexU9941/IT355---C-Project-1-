/**
 * @file ERR-58
 * @brief Demonstrates rule ERR-58 in C++.
 * 
 * This file defines a global object whose constructor may throw an exception. 
 * It demonstrates how to safely handle exceptions that may occur during the 
 * initialization of global objects before the main function executes.
 */

#include <iostream>
#include <stdexcept>

/**
 * @struct GlobalInitializer
 * @brief A structure that throws an exception in its constructor.
 * 
 * This structure simulates a scenario where an exception is thrown during 
 * the construction of a global object.
 */
struct GlobalInitializer {
    /**
     * @brief Constructor that throws an exception.
     * 
     * This constructor throws a runtime error to simulate a failure during
     * global object initialization.
     */
    GlobalInitializer() {
        throw std::runtime_error("Global object initialization failed");
    }
};

GlobalInitializer* globalInstance = nullptr; ///< Pointer to a global instance

/**
 * @brief Function to safely initialize global objects.
 * 
 * This function is called before main to handle exceptions during global 
 * object initialization. It catches any thrown exceptions and ensures the 
 * program terminates safely.
 */
void safeInitialization() {
    try {
        globalInstance = new GlobalInitializer();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught before main(): " << e.what() << std::endl;
        std::exit(EXIT_FAILURE); // Ensure program terminates safely
    }
}

/**
 * @struct RunBeforeMain
 * @brief A structure that executes initialization before main.
 * 
 * This structure ensures that the `safeInitialization` function runs before
 * the main function starts executing. It acts as a global initializer.
 */
struct RunBeforeMain {
    RunBeforeMain() { safeInitialization(); }
};

// This object ensures safeInitialization runs before main()
RunBeforeMain initializer;

int main() {
    std::cout << "Main function executing normally." << std::endl;
    return 0;
}
