/**
 * @file example.c
 * @brief Example file demonstrating the use of local variables.
 *
 * This file contains an example of how to use local variables within functions,
 * fulfilling the DCL20-C rule by ensuring that all local variables are properly
 * documented and used.
 */

#include <stdio.h>

/**
 * @brief Function prototype for foo.
 *
 * This function prototype declares the foo function.
 */
void foo(void); 

void foo(void) {
    int i = 3;
}

/**
 * @brief Main function.
 *
 * This is the entry point of the program. It defines a local variable i.
 * It then calls the foo function, and prints the value of i to the console.
 *
 * @return 0 on success.
 */

int main(){
    int i = 12;
    foo();
    printf("Value: %d\n", i); 
    return 0; 
}
