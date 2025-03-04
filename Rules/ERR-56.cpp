#include <iostream>
#include <vector>
#include <stdexcept>

class PositiveVector {
public:
    // Refuses negative 
    void addValue(int value) {
        if (value < 0) {
            throw std::invalid_argument("Cannot add a negative number.");
        }
        data.push_back(value);
    }

    // Prints the contents of the vector
    void print() const {
        std::cout << "Vector contents: ";
        for (int v : data) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> data;
};

int main() {
    PositiveVector vec;

    try {
        vec.addValue(10);
        vec.print();
        vec.addValue(20);
        vec.print();
        vec.addValue(-5); // Throws exception
        vec.print();
        vec.addValue(30);  // This won't be reached if an exception occurs
        vec.print();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    vec.print();

    return 0;
}
