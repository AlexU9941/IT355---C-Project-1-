#include <stdio.h>
void foo(void); 

void foo(void) {
    int i = 3;
}

int main(){
    int i = 12;
    foo();
    printf("Value: %d\n", i); 
    return 0; 
}