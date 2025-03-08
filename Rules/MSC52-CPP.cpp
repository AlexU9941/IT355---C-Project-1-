//Brady Olson
//IT355
//Coding example 3
//MSC52-CPP


#include <iostream>

bool isEven(int num)
{
    if((num % 2) == 0)
    {
        return true;
    }
    return false;
}


int main()
{
    int num;
    std::cout<<"Enter a number to determine if it is even: " << "\n";
    std::cin>>num;

    if(isEven(num))
    {   
        std::cout<<"the Number is even!" << "\n";
    }else{
        std::cout<<"The number is not even\n";
    }



}
