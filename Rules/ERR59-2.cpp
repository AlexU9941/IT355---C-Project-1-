/**
 * @file ERR59-2.cpp
 * @brief Demonstrates rule ERR59 in C++. Library file.
 * 
 * This file defines the `riskyFunction` which simulates an error by setting 
 * an error message and returning a failure code, without throwing an exception.
 */

#include "ERR59-2.h" ///< Header file defining the ErrorCode enum and function signature

/**
 * @brief Simulates a failure and sets an error message.
 * 
 * This function sets the error message passed by reference and returns 
 * an ErrorCode::FAILURE to indicate that the operation has failed.
 * 
 * @param errorMessage A reference to a string that will be set with the error message.
 * @return ErrorCode::FAILURE to indicate failure.
 */
ErrorCode riskyFunction(std::string& errorMessage) {
    // Simulate an error without throwing an exception
    errorMessage = "Operation failed due to an internal issue.";
    return ErrorCode::FAILURE;
}
