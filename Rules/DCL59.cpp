#include "DCL59.h"
#include <iostream>

int alpha; 

void alphaFunction(){
    std::cout<< "Alpha Function(): "<< alpha <<std::endl;
    alpha = 36; 

}


void betaFunction(){
    std::cout<< "Beta Function(): "<< alpha <<std::endl;
    alpha = 54; 

}

int main(){
    extern void alphaFunction();
    alphaFunction();
    betaFunction();
    alphaFunction();
    betaFunction();

}

