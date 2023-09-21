#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Open the input file.
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening input file." << endl;
        return 1;
    }

    // Open the output file for writing.
    ofstream outputFile("output.txt");
    if (!outputFile.is_open())
    {
        cout << "Error opening output file." << endl;
        return 1;
    }

    // Copy the contents from the input file to the output file.
    string line;
    while (getline(inputFile, line))
    {
        outputFile << line << endl;
    }

    // Close both files.
    inputFile.close();
    outputFile.close();

    cout << "Contents copied from input.txt to output.txt." << endl;

    return 0;
}
