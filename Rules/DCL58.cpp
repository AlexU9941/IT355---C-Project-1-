/**
 * @file example.cpp
 * @brief Example file demonstrating the use of custom binary function.
 *
 * This file contains an example of how to implement and use a custom binary function
 * object, fulfilling the DCL58-CPP rule by ensuring that all function objects are
 * properly documented and used.
 */

#include <functional> 
#include <iostream>
#include <string> 

/**
 * @class MyString
 * @brief A class that wraps a std::string.
 *
 * This class provides a simple wrapper around a std::string with a method to retrieve the stored string.
 */

class MyString{
    std::string data;
public:
/**
 * @brief Constructor for the MyString Class
 *Initializes the MyString object with the given string. 
 * @param data, which the string stores.
 */
    MyString(const std::string data): data(data){}
/**
 * @brief Gets the stored string.
 * Returns a constant reference to the string that has been stored. 
 * @return the stored string. 
 */
    const std::string &get_data() const { return data; }
};

/**
 * @struct my_plus
 * @brief A custom binary function object.
 *
 * This structure defines a custom binary function object that concatenates
 * a std::string and a MyString.
 */
struct my_plus : std::binary_function<std::string, MyString, std::string>{
  /**
     * @brief Concatenates two strings.
     *
     * This operator concatenates a std::string and a MyString.
     *
     * @param lhs The left-hand side string.
     * @param rhs The right-hand side MyString.
     * @return The concatenated string.
     */
    std::string operator()(const std::string &lhs, const MyString &rhs) const{
        return lhs + rhs.get_data();
    }
};

/**
 * @brief Demonstrates the use of the my_plus function object.
 *
 * This function creates two strings, concatenates them using the my_plus
 * function object, and prints the result to the console.
 */
void f() {
    std::string s1 ("My String");
    MyString s2 (" + Your String");
    my_plus p;

    std::cout<< p(s1, s2) << std::endl;
}

/**
 * @brief Main function.
 *
 * This is the entry point of the program. It calls the f function to demonstrate
 * the use of the my_plus function object.
 *
 * @return 0 on success.
 */
int main(){ 
    f();
}
