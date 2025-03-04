#include <iostream>
#include "ERR-59-2.h"

int main() {
    std::string errorMsg;

    /*run with:
    g++ -fPIC -shared -o libERR-59-2.so ERR-59-2.cpp
    g++ -o ERR-59-1 ERR-59-1.cpp -L. -lERR-59-2
    LD_LIBRARY_PATH=. ./ERR-59-1
    */
    
    // Call the function from the shared library
    if (riskyFunction(errorMsg) == ErrorCode::FAILURE) {
        std::cerr << "Error: " << errorMsg << std::endl;
        return 1;
    }

    std::cout << "Operation succeeded!" << std::endl;
    return 0;
}
