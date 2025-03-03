#include <iostream>


template <typename Arg, typename std::enable_if<std::is_integral<Arg>::value>::type * = nullptr>
int add(Arg f, Arg s){
    return f + s; 
}

template <typename Arg2, typename... Ts, typename std::enable_if<std::is_integral<Arg2>::value>::type * = nullptr> 
int add(Arg2 f, Ts...rest){
    return f + add2(rest...); 
}

int main(){
    int result1 = add(3,2);  
    std::cout<<"First returned solution of: "<< result1 <<std::endl; 
    int result2 = add(8,1);  
    std::cout<<"Second returned solution of: "<< result2 <<std::endl; 
}