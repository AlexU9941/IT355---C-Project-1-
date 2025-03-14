/**
 * @file DCL51.h
 * @brief Header file for the TestClass.
 *
 * This file contains the definition of the TestClass.
 * It fulfills the DCL51-CPP rule by ensuring that all header files have include guards.
 */

#ifndef _DCL51_Header
#define _DCL51_Header

#include <string>


/**
 * @file TestClass
 * @brief Method to test the code
 *Method prints a test message. 
 * @returns resulting string with test result
 */
class TestClass{
    public: 
    std::string test() const;
};

#endif // _DCL51_Header
