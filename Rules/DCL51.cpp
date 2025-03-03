#include "DCL51.h"
#include <iostream>
#include <string> 
using namespace std;


std::string TestClass::test() const{
    std::cout<<"This is my test."<< std::endl;
    return "True!"; 
}

int main() {
    TestClass dcl_obj;
    std::cout<< dcl_obj.test() << std::endl; 
    return 0; 
}

