#include <stdexcept>
#include <iostream>

int fact(int i) noexcept(false){
    if (i < 0){
        //meaning negative factorials are defined
        throw std::domain_error("i must be >= 0");
    }

    static int cache[17];
    if (i < (sizeof(cache) / sizeof(int))){
        if (0 == cache[i]){
            cache[i] = i > 0 ? i *fact(i-1) : 1;  
        }
        return cache[i]; 
    }
    return i > 0 ? i * fact(i-1) : 1; 
}

int main(){
    try{
        std::cout << "7! = " << fact(7) << "\n";
    } catch (const std::exception& e){
        std::cerr << e.what() << "\n"; 
    }
}