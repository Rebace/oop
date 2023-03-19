#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>
#include <climits>
#include <optional>

using namespace std;

using Matrix3x3 = double[3][3];
using Matrix2x2 = double[2][2];

double CountingDeterminantMatrix2x2(Matrix3x3 matrix, int elemLineNumber, int elemColumnNumber)
{
    Matrix2x2 matrix2x2;
    size_t line2x2 = 0;
    size_t column2x2;

    for (size_t line = 0; line < 3; ++line)
    {
        if (line == elemLineNumber)
        {
            continue;
        }

        column2x2 = 0;

        for (size_t column = 0; column < 3; ++column)
        {
            if (column == elemColumnNumber)
            {
                continue;
            }

            matrix2x2[line2x2][column2x2] = matrix[line][column];
            ++column2x2;
        }

        ++line2x2;
    }
    return (matrix2x2[0][0] * matrix2x2[1][1] - matrix2x2[1][0] * matrix2x2[0][1]) * 
        pow(-1, elemLineNumber + elemColumnNumber + 2);
}

int CountingDeterminantMatrix3x3(Matrix3x3 matrix)
{
    int det = 0;
    for (size_t line = 0; line < 3; ++line)
    {
        det += CountingDeterminantMatrix2x2(matrix, line, 0) * matrix[line][0];
    }

    return det;
}

bool invertingMatrix(Matrix3x3 matrix, Matrix3x3 invertMatrix)
{
    double det = 0;

    det = CountingDeterminantMatrix3x3(matrix);
    
    if (det == 0)
    {
        return false;
    }

    for (size_t line = 0; line < 3; ++line)
    {
        for (size_t column = 0; column < 3; ++column)
        {
            invertMatrix[column][line] = CountingDeterminantMatrix2x2(matrix, line, column) / det;
            if (invertMatrix[column][line] == 0)
            {
                invertMatrix[column][line] = 0;
            }
        }
    }
    return true;
}

bool ReadMatrixFromFile(const string& fileName, Matrix3x3& matrix)
{
    ifstream fileIn;
    fileIn.open(fileName);

    if (!fileIn.is_open())
    {
        return false;
    }

    for (size_t line = 0; line < 3; ++line)
    {
        for (size_t column = 0; column < 3; ++column)
        {
            if (!(fileIn >> matrix[line][column]))
            {
                return false;
            }
        }
    }
    return true;
}

void PrintMatrix(Matrix3x3 matrix)
{ 
    for (size_t line = 0; line < 3; ++line)
    {
        for (size_t column = 0; column < 3; ++column)
        {
            cout << setprecision(4) << setw(10) << floor(matrix[line][column] * 1000) / 1000;
        }
        cout << endl;
    }
}

optional<string> GetMatrixFilename(int argc, char** argv)
{
    if (argc != 2)
    {
        cout << "Invalid arguments count" << endl;
        cout << "Usage: Invert.exe <matrix file name>" << endl;
        return nullopt;
    }

    return argv[1];
}

int main(int argc, char* argv[])
{
    auto const matrixFilename = GetMatrixFilename(argc, argv);
    if (!matrixFilename)
    {
        return 1;
    }

    Matrix3x3 matrix;
    if (!ReadMatrixFromFile(matrixFilename.value(), matrix))
    {
        cout << "Error with reading matrix" << endl;
        return 1;
    }

    Matrix3x3 ivertMatrix;
    if (!invertingMatrix(matrix, ivertMatrix))
    {
        cout << "Matrix can not be inverted" << endl;
        return 1;
    }

    PrintMatrix(ivertMatrix);
}
