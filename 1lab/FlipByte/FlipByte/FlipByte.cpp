#include <iostream>
#include <string>

using namespace std;

int Reverse(int b)
{
    int a = 0;
    for (int i = 0; i < 8; i++)
        if ((b & (1 << i)) != 0)
            a |= 1 << (7 - i);
    return a;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count" << endl;
        return 1;
    }

    int byte;
    try
    {
        byte = stoi(argv[1]);
    }
    catch (const std::exception&)
    {
        cout << "The argument is not a number" << endl;
        return 1;
    }

    if ((byte < 0) || (byte > 255))
    {
        cout << "The argument does not consist of a single byte" << endl;
        return 1;
    }

    cout << Reverse(byte) << endl;
}
