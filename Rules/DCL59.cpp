#include "DCL59.h"
#include <iostream>

/**
 * @brief Definition of the external variable alpha.
 */
int alpha; 

/**
 * @brief Function that prints and modifies the value of alpha.
 *
 * This function prints the current value of alpha, then sets it to 36.
 */

void alphaFunction(){
    std::cout<< "Alpha Function(): "<< alpha <<std::endl;
    alpha = 36; 

}

/**
 * @brief Function that prints and modifies the value of alpha.
 *
 * This function prints the current value of alpha, then sets it to 54.
 */
void betaFunction(){
    std::cout<< "Beta Function(): "<< alpha <<std::endl;
    alpha = 54; 

}

/**
 * @brief Main function.
 *
 * This is the entry point of the program. It calls alphaFunction and betaFunction
 * multiple times to demonstrate their behavior.
 *
 * @return 0 on success.
 */
int main(){
    extern void alphaFunction();
    alphaFunction();
    betaFunction();
    alphaFunction();
    betaFunction();

}

