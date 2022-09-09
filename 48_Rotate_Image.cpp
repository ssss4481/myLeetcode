#include <iostream>
#include "Matrix.hpp"
#include <vector>

using namespace std;


void swap4(vector<vector<int>>& matrix, vector<vector<int>>& indice)
{
    int temp = matrix[indice[3][0]][indice[3][1]]; // temp = LD
    for(int i = 3; i >= 1; --i)
    {
        matrix[indice[i][0]][indice[i][1]] = matrix[indice[i-1][0]][indice[i-1][1]]; //RU = LU; RD = RU;...
    }
    matrix[indice[0][0]][indice[0][1]] = temp;
}

void swap4alt(vector<vector<int>>& matrix, vector<int>& LU, vector<int>& RU, vector<int>& RD, vector<int>& LD)
{
    int temp = matrix[LD[0]][LD[1]]; // temp = LD
    matrix[LD[0]][LD[1]] = matrix[RD[0]][RD[1]];
    matrix[RD[0]][RD[1]] = matrix[RU[0]][RU[1]];
    matrix[RU[0]][RU[1]] = matrix[LU[0]][LU[1]];
    matrix[LU[0]][LU[1]] = temp;
}



void rotate(vector<vector<int>>& matrix)
{
    int length = matrix.size();
    int start = 0;
    while(length > 1)
    {
        vector<int> LU {start, start};
        vector<int> RU {start, start+length-1};
        vector<int> RD {start+length-1, start+length-1};
        vector<int> LD {start+length-1, start};
        for(int i = 1; i <= length - 1; ++i )
        {
            //vector<vector<int>> indice{LU, RU, RD, LD};
            //swap4(matrix, indice);
            swap4alt(matrix, LU, RU, RD, LD);
            ++LU[1];
            ++RU[0];
            --RD[1];
            --LD[0];
        }
        length -= 2;
        ++start;
    }
}

void swap4alt2(vector<vector<int>>& matrix, const int& start, const int& length)
{
    vector<int> LU {start, start};
    vector<int> RU {start, start+length-1};
    vector<int> RD {start+length-1, start+length-1};
    vector<int> LD {start+length-1, start};
    for(int i = 1; i <= length - 1; ++i )
    {
        int temp = matrix[LD[0]][LD[1]]; // temp = LD
        matrix[LD[0]][LD[1]] = matrix[RD[0]][RD[1]];
        matrix[RD[0]][RD[1]] = matrix[RU[0]][RU[1]];
        matrix[RU[0]][RU[1]] = matrix[LU[0]][LU[1]];
        matrix[LU[0]][LU[1]] = temp;
        ++LU[1];
        ++RU[0];
        --RD[1];
        --LD[0];
    }
}


void rotate2(vector<vector<int>>& matrix)
{
    int length = matrix.size();
    int start = 0;
    while(length > 1)
    {
        swap4alt2(matrix, start, length);
        length -= 2;
        ++start;
    }
}




int main()
{
    vector<vector<int>> matrix;
    matrixMethod::Matrix_generation(matrix);
    matrixMethod::printMatrix(matrix);
    cout << "\n";
    rotate2(matrix);
    matrixMethod::printMatrix(matrix);
    return 0;
}