//Brady Olson
//IT355
//Recommendation STR07-C

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char source[] = "This is data allocated string for my rule STR07-C!";
    char destination[10]; // Small buffer

    // Safe function: strncpy() limits copied characters
    strncpy(destination, source, sizeof(destination) - 1);

    destination[sizeof(destination) - 1] = '\0';

    cout << "Copied string: " << destination << endl;

    return 0;
}

