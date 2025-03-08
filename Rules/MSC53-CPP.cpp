//Brady Olson
//IT355
//Coding example 3
//MSC53-CPP


#include <iostream>
#include <cstdlib>

[[noreturn]] void isOdd(int num)
{
    if((num % 2) != 0)
    {
        throw "Odd Number Entered";
    }
    std::exit(0);
}

int main()
{
    int num;

    std::cout<<"Enter a number to determine if it is Odd. Remember if it is not odd the program will stop running.\n";
    std::cin>>num;

    isOdd(num);
}
