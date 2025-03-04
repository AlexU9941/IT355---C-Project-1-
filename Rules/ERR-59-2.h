#ifndef ERR_59_2_H
#define ERR_59_2_H

#include <string>

// Define an enum for error handling
enum class ErrorCode {
    SUCCESS,
    FAILURE
};

// Function that simulates an operation that might fail
ErrorCode riskyFunction(std::string& errorMessage);

#endif
