//Brady Olson
//IT355
//Recommendation STR06-C

#include <iostream>
#include <fstream>
#include <cstring> 
#include <cstdlib>  

using namespace std;

// Function to count words using strtok()
int wordCountFun(char* content) {
    char* wordTok;
    int wordCount = 0;

    wordTok = strtok(content, " ;:?!.\t\n");

    while (wordTok != NULL) {
        wordCount++;
        wordTok = strtok(NULL, " ;:?!.\t\n");
    }

    return wordCount;
}


int main() {
    string fileName;
    char* content = nullptr;
    int wordCount = 0, lineCount = 0;

    // Ask user for file name
    cout << "Enter file to be assessed: ";
    cin >> fileName;

    // Open file using C++ file stream
    ifstream file(fileName, ios::binary);

    // Check if file opened successfully
    if (!file) {
        cerr << "File could not be opened\n";
        return 1; 
    }

    // Determine file size
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, ios::beg);

    // Allocate memory for file content
    content = new char[fileSize + 1];

    if (!content) {
        cerr << "Memory allocation failed\n";
        file.close();
        return 1;
    }

    // Read file into memory
    file.read(content, fileSize);
    content[fileSize] = '\0';  

    file.close(); // Close the file

    // Make a copy for line counting, since strtok() modifies the string
    char* contentCopy = new char[fileSize + 1];
    strcpy(contentCopy, content);

    // Count words and lines
    wordCount = wordCountFun(content);
    

    // Output results
    cout << "Word Count: " << wordCount << endl;


    // Free allocated memory
    delete[] content;
    delete[] contentCopy;

    return 0; 
}


