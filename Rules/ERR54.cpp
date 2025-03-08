/**
 * @file ERR54.cpp
 * @brief Demonstrates rule ERR54 in C++.
 * 
 * This file defines a base exception class and a derived exception class, 
 * both inheriting from std::exception. It also defines a class that throws 
 * exceptions conditionally and showcases proper exception handling.
 */

#include <iostream>
#include <exception>

/**
 * @class baseClass
 * @brief A custom exception class derived from std::exception.
 * 
 * This class overrides the what() function to return a custom message.
 */
class baseClass : public std::exception {
public:
    /**
     * @brief Returns an error message describing the exception.
     * @return A C-string containing the exception message.
     */
    virtual const char* what() const noexcept override {
        return "baseClass occurred";
    }
};

/**
 * @class derivedClass
 * @brief A derived exception class extending baseClass.
 * 
 * This class overrides the what() function to provide a more specific error message.
 */
class derivedClass : public baseClass {
public:
    /**
     * @brief Returns an error message describing the derived exception.
     * @return A C-string containing the derived exception message.
     */
    virtual const char* what() const noexcept override {
        return "derivedClass occurred";
    }
};

/**
 * @class MyClass
 * @brief A class containing a function that may throw exceptions.
 * 
 * This class has a method that throws either a baseClass or derivedClass 
 * exception based on the input parameter.
 */
class MyClass {
public:
    /**
     * @brief Throws an exception based on the input flag.
     * 
     * @param throwDerived If true, throws a derivedClass exception. Otherwise, throws a baseClass exception.
     * @throws derivedClass If throwDerived is true.
     * @throws baseClass If throwDerived is false.
     */
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
