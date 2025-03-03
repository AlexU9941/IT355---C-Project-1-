#include <stdarg.h>
#include <stdio.h>

enum { va_eol = -1} ; 

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
int main(){
    int avg = average(1,6,7,4,8, va_eol);
    return avg; 
}