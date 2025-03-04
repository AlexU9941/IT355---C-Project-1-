#include <iostream>
#include <exception>

class baseClass : public std::exception {
public:
    virtual const char* what() const noexcept override {
        return "baseClass occurred";
    }
};

class derivedClass : public baseClass {
public:
    virtual const char* what() const noexcept override {
        return "derivedClass occurred";
    }
};

class MyClass {
public:
    void riskyFunction(bool throwDerived) {
        if (throwDerived) {
            throw derivedClass();
        } else {
            throw baseClass();
        }
    }
};

int main() {
    MyClass obj;

    try {
        obj.riskyFunction(true);
    }
    catch (const derivedClass& e) { // Most derived type first
        std::cout << "Caught: " << e.what() << std::endl;
    }
    catch (const baseClass& e) { // Base type second
        std::cout << "Caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) { // Standard exception last
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
