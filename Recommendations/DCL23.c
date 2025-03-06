/**
 * @file example.c
 * @brief Example file demonstrating the use of function declarations and definitions.
 *
 * This file contains an example of how to declare and define functions,
 * fulfilling the DCL23-C rule by ensuring that all function declarations and definitions
 * are properly documented and used.
 */

#include <stdio.h>
#include <stdarg.h>

/**
 * @brief Prints a message.
 *
 * This function prints "Omnissiah be praised!" to the console.
 */
void print_message(void);

/**
 * @brief Prints another message.
 *
 * This function prints "The machine spirit is pleased!" to the console.
 */
void print_message2(void);

/**
 * @brief Main function.
 *
 * This is the entry point of the program.
 * It calls both print functions to print messages to the console.
 *
 * @return 0 on success.
 */
int main(){
    print_message(); 
    print_message2(); 
    return 0; 
}

/**
 * @brief Prints a message.
 *
 * This function prints "Omnissiah be praised!" to the console.
 */
void print_message(){
    printf("Omnissiah be praised!\n");
}

/**
 * @brief Prints another message.
 *
 * This function prints "The machine spirit is pleased!" to the console.
 */
void print_message2(){
    printf("The machine spirit is pleased!\n");
}






