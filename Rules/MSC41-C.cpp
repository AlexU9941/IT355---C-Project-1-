//Brady Olson
//IT355
//Coding example 3
//MSC41-C

#include <iostream>
#include <fstream>
using namespace std;

bool validUsername(const string& username)
{
    ifstream inputFile("Usernames.txt");
    if (!inputFile)
    {
        cout << "Error retrieving usernames." << endl;
        return false;
    }

    string line;
    while (getline(inputFile, line))
    {
        if (username == line)  // Simplified comparison
        {
            inputFile.close();
            return true;
        }
    }
    inputFile.close();
    return false;
}

int main()
{
    string user;
    cout<<"Enter username: "<<endl;
    cin>>user;

    if(validUsername(user))
    {
        cout<<"This is a valid username"<<endl;
    }else{
        cout<<"This is not a valid username"<<endl;
    }


}
