//Brady Olson
//IT355
//Coding example 3
//MSC37-CPP
#include <iostream>

using namespace std;

int getNumber() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num > 0) {
        return num;
    }
   
    return 0;
}

int main() {
    int result = getNumber();
    cout << "You entered: " << result << endl;
    return 0;
}

