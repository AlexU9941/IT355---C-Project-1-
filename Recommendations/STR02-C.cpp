//Brady Olson
//IT355
//Recommendation STR02-C


#include <iostream>
#include <string>

using namespace std;

string purifyData(string input)
{
    string result;

    for(char x : input)
    {
        if(x != '/')
        {
            result += x;
        }
    }

    return result;

}

int main ()
{
    string input, result;
    cout<<"Please enter words."<<endl;
    cin>>input;

    result = purifyData(input);

    cout<<result<<endl;

    return 0;
}
