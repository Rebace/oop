#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

using Matrix3x3 = double[3][3];
using Matrix2x2 = double[2][2];

int CountingDeterminantMatrix2x2(Matrix3x3 matrix, int elemLineNumber, int elemColumnNumber)
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
        return 1;
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
    return 0;
}

bool ReadMatrixFromFile(ifstream& file, Matrix3x3& matrix)
{
    for (size_t line = 0; line < 3; ++line)
    {
        for (size_t column = 0; column < 3; ++column)
        {
            if (!(file >> matrix[line][column]))
            {
                return true;
            }
        }
    }
    return false;
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

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Invalid arguments count" << endl;
        return 1;
    }

    ifstream fileIn;
    fileIn.open(argv[1]);

    if (!fileIn.is_open())
    {
        cout << "Failed to open" << endl;
        return 1;
    }

    Matrix3x3 matrix;
    if (ReadMatrixFromFile(fileIn, matrix))
    {
        cout << "Input matrix error" << endl;
        return 1;
    }

    Matrix3x3 ivertMatrix;
    invertingMatrix(matrix, ivertMatrix);

    PrintMatrix(ivertMatrix);
}
