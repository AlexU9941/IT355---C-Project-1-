#include "DCL51.h"
#include <iostream>
#include <string> 
using namespace std;

/**
 * @brief Implementation of the test method
 * Method prints "This is my test." to the console and returns "True!" 
 *
 * @returns "True!" upon success.
 */
std::string TestClass::test() const{
    std::cout<<"This is my test."<< std::endl;
    return "True!"; 
}

/**
 * @brief Main function definition here
 * Entry point of the program here. Creats an instance of TestClass, before calling the 
 *testing method, and prints the result to the console.
 * @returns 0 upon success.
 */

int main() {
    TestClass dcl_obj;
    std::cout<< dcl_obj.test() << std::endl; 
    return 0; 
}

