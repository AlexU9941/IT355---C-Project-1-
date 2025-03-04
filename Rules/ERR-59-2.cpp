#include "ERR-59-2.h"

ErrorCode riskyFunction(std::string& errorMessage) {
    // Simulate an error without throwing an exception
    errorMessage = "Operation failed due to an internal issue.";
    return ErrorCode::FAILURE;
}
