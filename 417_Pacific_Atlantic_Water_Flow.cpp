#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

void DFS(vector< vector<int> > &heights, const int &m, const int &n, const int &prev_height, vector< vector <bool> > &visit)
{
    if(m < 0 || n < 0 || m >= heights.size() || n >= heights[0].size() || prev_height > heights[m][n] || visit[m][n])
        return;
    //record[m][n] = true;
    visit[m][n] = true;
    DFS(heights, m+1, n, heights[m][n], visit);
    DFS(heights, m-1, n, heights[m][n], visit);
    DFS(heights, m, n+1, heights[m][n], visit);
    DFS(heights, m, n-1, heights[m][n], visit);
}

vector< vector<int> > pacificAtlantic(vector< vector<int> >& heights)
{
    vector< vector<bool> > Pacific (heights.size(), vector<bool>(heights[0].size(), false));
    vector< vector<bool> > Atlantic (heights.size(), vector<bool>(heights[0].size(), false));

    vector< vector<int> > ret;

    for(int i = 0; i < heights[0].size(); ++i)
    {
        DFS(heights, 0, i, 0, Pacific);
        DFS(heights, heights.size()-1, i, 0, Atlantic);
    }
    for(int i = 0; i < heights.size(); ++i)
    {
        DFS(heights, i, 0, 0, Pacific);
        DFS(heights, i, heights[0].size()-1, 0, Atlantic);
    }

    for(int i = 0; i < heights.size(); ++i)
    {
        for(int j = 0; j < heights[0].size(); ++j)
        {
            if(Pacific[i][j] && Atlantic[i][j])
                ret.push_back({i, j});
        }
    }
    return ret;
}

int main()
{
    vector<vector<int>> heights = matrixMethod::Matrix_generation(0);
    vector<vector<int>> ret = pacificAtlantic(heights);
    //cout << "here\n";
    test(ret);

    return 0;
}