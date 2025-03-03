#include <stdio.h>
#include <stdarg.h>

void print_error(const char* format, ...){
    va_list args; 

    va_start(args, format);

    vprintf(format, args);

    va_end(args);
}


int main(){
const char *error_msg = "Error Occured"; 
    print_error("%d: %s\n", 15, error_msg); 

    //print_error("%s: %d\n", 15, error_msg); 
    //WARNING: UNCOMMENTING THIS LINE WILL CAUSE UNDEFINED BEHAVIOR
   return 0;


}

