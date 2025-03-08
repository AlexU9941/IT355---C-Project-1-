//Brady Olson
//IT355
//Coding example 3
//MSC54-CPP

#include <iostream>
#include <csignal>

void signal_handler(int signal)
{

    std::cout<<"Signal Interupt Code: " << signal << "\n";

    std::exit(signal);

}

int main()
{

signal(SIGSEGV, signal_handler);

int count;

while(true)
{
    std::cout<< count <<"\n";
    count++;
    if(count == 5 )
    {
        raise(SIGSEGV);
    }
}

return 0;

}
