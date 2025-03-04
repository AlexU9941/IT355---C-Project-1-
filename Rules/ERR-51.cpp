#include <iostream>
#include <stdexcept>

// Custom exception classes
class PositiveError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Positive number error occurred!";
    }
};

class NegativeError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Negative number error occurred!";
    }
};

void processNumber(int num) {
    if (num == 0) {
        std::cout << "Success: Zero passed in.\n";
    } else if (num > 0) {
        throw PositiveError();
    } else {
        throw NegativeError();
    }
}

int main() {
    int num;

    // Example inputs
    num = 0;
    try {
        processNumber(num);
    } catch (const PositiveError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const NegativeError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    num = 5;
    try {
        processNumber(num);
    } catch (const PositiveError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const NegativeError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    num = -3;
    try {
        processNumber(num);
    } catch (const PositiveError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const NegativeError& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }

    return 0;
}
