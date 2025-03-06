#include <iostream>
/**
 * @brief Adds two integers in compliance with DCL50-CPP.
 * DCL50-CPP states: "Do not define a C-style variadic function"
 * This function takes two integers as input and returns their sum.
 *
 * @param[in] a First integer to add.
 * @param[in] b Second integer to add.
 * @return Sum of the two integers.
 */
template <typename Arg, typename std::enable_if<std::is_integral<Arg>::value>::type * = nullptr>
int add(Arg f, Arg s){
    return f + s; 
}

template <typename Arg2, typename... Ts, typename std::enable_if<std::is_integral<Arg2>::value>::type * = nullptr> 
int add2(Arg2 f, Ts...rest){
    return f + add2(rest...); 
}

/** 
*@brief: Main method to ensure the program works
*@param: Calls an instance of adding methods.
*@returns correct answers of returned solutions
*/
int main(){
    int result1 = add(3,2);  
    std::cout<<"First returned solution of: "<< result1 <<std::endl; 
    int result2 = add2(8,1);  
    std::cout<<"Second returned solution of: "<< result2 <<std::endl; 
}
