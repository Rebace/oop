#include <iostream>
#include <string>
#include <optional>

using namespace std;

int Reverse(int num)
{
    num = ((num & 0b00001111) << 4) | ((num & 0b11110000) >> 4);
    num = ((num & 0b00110011) << 2) | ((num & 0b11001100) >> 2);
    num = ((num & 0b01010101) << 1) | ((num & 0b10101010) >> 1);

    return num;
}

optional<string> GetByte(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Invalid arguments count" << endl;
        cout << "Usage: FlipByte.exe <byte for reverse>" << endl;
        return nullopt;
    }

    return argv[1];
}

int main(int argc, char* argv[])
{
    auto const byte = GetByte(argc, argv);
    if (!byte)
    {
        return 1;
    }

    try
    {
        double b = stod(byte.value());
        int byte = b;

        if ((b < 0) || (b > 255))
        {
            throw -1;
        }

        if (b - byte > 0)
        {
            throw 1.1;
        }

        cout << Reverse(byte) << endl;
    }
    catch (invalid_argument e)
    {
        cout << "The argument is not a number" << endl;
        return 1;
    }
    catch (int)
    {
        cout << "The argument does not consist of a single byte" << endl;
        return 1;
    }
    catch (double)
    {
        cout << "Not a int number" << endl;
        return 1;
    } 
}
