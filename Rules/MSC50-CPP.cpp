//Brady Olson
//IT355
//code example
//MSC50-CPP

#include <string>
#include <random>
#include <iostream>
using namespace std;


int randomNumberGenerator()
{
    uniform_int_distribution<int> distribution(1,10);

    random_device rd;
    mt19937 engine(rd());

    return distribution(engine);
}

int main()
{
    int x, randNum;

    randNum = randomNumberGenerator();

cout<<"Guess a number 1-10"<<endl;
cin>>x;

if(x == randNum)
{
    cout<<"\nCongrats you Won!"<<endl;
}else{
    cout<<"\nYou Lost!"<<endl;
}

cout<<"The correct number was "<<randNum<<endl;


}
