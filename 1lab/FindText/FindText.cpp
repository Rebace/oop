#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool FindStingInStream(istream& haystack, const string& needle)
{
    bool found = false;
    string line;

    for (int lineIndex = 1; getline(haystack, line); ++lineIndex)
    {
        auto pos = line.find(needle);
        if (pos != string::npos)
        {
            found = true;
            cout << lineIndex << endl;
        }
    }
    return found;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count" << endl;
        return 1;
    }

    ifstream fileIn;
    fileIn.open(argv[1]);

    if (!fileIn.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }

    if (!FindStingInStream(fileIn, argv[2]))
    {
        cout << "Text not found" << endl;
        return 1;
    }

    fileIn.clear();
}
