#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void printVector(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}


vector<vector<int>> diagonalSort(vector<vector<int>>& mat)
{
    int m = mat.size();
    int n = mat[0].size();

    //[0][0] to [0][n]
    for(int start_col = 0; start_col < (n - 1); ++start_col)
    {
        vector<int> arr;
        int ir = 0;
        int ic = start_col;
        while(ir < m && ic < n)
        {
            arr.push_back(mat[ir][ic]);
            ++ir;
            ++ic;
        }
        sort(arr.begin(), arr.end());
        ir = 0;
        ic = start_col;
        for(int i = 0; i < arr.size(); ++i)
        {
            mat[ir][ic] = arr[i];
            ++ir;
            ++ic;
        }
    }
    //(1, 0) to ()
    for(int start_row = 1; start_row < (m - 1); ++start_row)
    {
        vector<int> arr;
        int ir = start_row;
        int ic = 0;
        while(ir < m && ic < n)
        {
            arr.push_back(mat[ir][ic]);
            ++ir;
            ++ic;
        }
        sort(arr.begin(), arr.end());
        ir = start_row;
        ic = 0;
        for(int i = 0; i < arr.size(); ++i)
        {
            mat[ir][ic] = arr[i];
            ++ir;
            ++ic;
        }
    }

    return mat;
}




int main()
{
    int m, n;
    //cout << "m = \n";
    cin >> m;
    //cout << "n = \n";
    cin >> n;
    vector< vector<int> > matrix (m, vector<int>(n));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            //cout << "row " << i+1 << ", ("<< i+1 << ", " << j+1 << ")= ";
            cin >> matrix[i][j];
        }
    }
    printVector(matrix);
    diagonalSort(matrix);
    printVector(matrix);




    return 0;
}