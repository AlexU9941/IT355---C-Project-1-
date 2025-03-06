/**
 * @file ERR-59-2.hERR-59-2.cpp
 * 
 * This file defines the `ErrorCode` enum and the `riskyFunction` function. 
 * The `riskyFunction` simulates an operation that may fail and sets an 
 * error message accordingly.
 */

#ifndef ERR_59_2_H
#define ERR_59_2_H

#include <string>

/**
 * @enum ErrorCode
 * @brief Enumerates the result codes for operations.
 * 
 * This enum provides the possible result codes returned by operations 
 * to indicate success or failure.
 */
enum class ErrorCode {
    SUCCESS, ///< Indicates the operation was successful.
    FAILURE  ///< Indicates the operation failed.
};

/**
 * @brief Simulates an operation that might fail and sets an error message.
 * 
 * This function simulates an operation that may fail. If it fails, it 
 * sets the error message passed by reference and returns `ErrorCode::FAILURE`.
 * 
 * @param errorMessage A reference to a string that will be set with the error message.
 * @return ErrorCode::FAILURE to indicate failure.
 */
ErrorCode riskyFunction(std::string& errorMessage);

#endif
