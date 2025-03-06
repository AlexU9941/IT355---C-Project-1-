/**
 * @file example.c
 * @brief Example file demonstrating the use of variadic functions.
 *
 * This file contains an example of how to implement and use a variadic function
 * to calculate the average of a list of integers, fulfilling the DCL10-C rule by
 * ensuring that all variadic functions are properly documented and used.
 */

#include <stdarg.h>
#include <stdio.h>

/**
 * @enum
 * @brief Enumeration for end-of-list marker.
 *
 * This enumeration defines a marker to indicate the end of the list of arguments.
 */
enum { va_eol = -1} ; 

/**
 * @brief Computes the average of a list of integers.
 *
 * This function computes the average of a list of integers passed as variadic arguments.
 * The list of arguments must be terminated with the va_eol marker.
 *
 * @param first The first integer in the list.
 * @param ... Additional integers in the list, terminated by va_eol.
 * @return The average of the integers.
 */
unsigned int average(int first, ...){
    unsigned int count = 0; 
    unsigned int sum = 0; 
    int i = first;
    va_list args; 

    va_start(args, first);

    while (i != va_eol){
        sum += i;
        count++; 
        i = va_arg(args, int);
        printf("%d\n", i);
    }

    va_end(args);
    return (count ? (sum/count): 0); 
}

/**
 * @brief Main function.
 *
 * This is the entry point of the program. It calls the average function with a list
 * of integers and prints the result to the console.
 *
 * @return The average of the integers.
 */
int main(){
    int avg = average(1,6,7,4,8, va_eol);
    return avg; 
}
