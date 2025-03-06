/**
 * @file example.c
 * @brief Example file demonstrating the use of variadic functions for error printing.
 *
 * This file contains an example of how to implement and use a variadic function
 * to print error messages, fulfilling the DCL11-C rule by ensuring that all variadic
 * functions are properly documented and used.
 */


#include <stdio.h>
#include <stdarg.h>


/**
 * @brief Prints an error message.
 *
 * This function prints an error message using a variadic argument list.
 *
 * @param format The format string for the error message.
 * @param ... Additional arguments for the format string.
 */
void print_error(const char* format, ...){
    va_list args; 

    va_start(args, format);

    vprintf(format, args);

    va_end(args);
}

/**
 * @brief Main function.
 *
 * This is the entry point of the program. It calls the print_error function with
 * a format string and arguments, and prints the result to the console.
 *
 * @return 0 on success.
 */
int main(){
const char *error_msg = "Error Occured"; 
    print_error("%d: %s\n", 15, error_msg); 

    //print_error("%s: %d\n", 15, error_msg); 
    //WARNING: UNCOMMENTING THIS LINE WILL CAUSE UNDEFINED BEHAVIOR
   return 0;


}

