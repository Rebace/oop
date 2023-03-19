#include <iostream>
#include <fstream>
#include <string>
#include <optional>

using namespace std;

struct Args
{
    string inputFileName;
    string word;
};

optional<Args> ParseArgs(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Invalid arguments count" << endl;
        cout << "Usage: FindText.exe <input file name> <search word>" << endl;
        return nullopt;
    }

    Args args;
    args.inputFileName = argv[1];
    args.word = argv[2];

    return args;
}

bool InitializeFile(ifstream& fileIn, const string& filename)
{
    fileIn.open(filename);
    if (!fileIn.is_open())
    {
        return false;
    }

    return true;
}

bool FindStringInStreamAndPrint(istream& input, const string& word)
{
    bool found = false;
    string line;

    for (size_t lineIndex = 1; getline(input, line); ++lineIndex)
    {
        size_t pos = line.find(word);
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
    auto args = ParseArgs(argc, argv);

    if (!args)
    {
        return 1;
    }

    string word = args->word;
    if (!word.size())
    {
        cout << "There is no word to search for" << endl;
        return 1;
    }

    ifstream fileIn;
    if (!InitializeFile(fileIn, args->inputFileName))
    {
        cout << "Failed to open input file '" << args->inputFileName << "' for reading" << endl;
        return 1;
    }

    if (!FindStringInStreamAndPrint(fileIn, word))
    {
        cout << "Text not found" << endl;
        return 1;
    }

    return 0;
}
