#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(vector<vector<int>>& image, vector<vector<int>>& visit, int sr, int sc, int newColor, int oldColor)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || visit[sr][sc] == 1 || image[sr][sc] != oldColor)
            return;
        visit[sr][sc] = 1;
        image[sr][sc] = newColor;
        DFS(image, visit, sr+1, sc, newColor, oldColor);
        DFS(image, visit, sr-1, sc, newColor, oldColor);
        DFS(image, visit, sr, sc+1, newColor, oldColor);
        DFS(image, visit, sr, sc-1, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        vector<vector<int>> visit(image.size(), vector<int>(image[0].size(), 0));
        DFS(image, visit, sr, sc, color, image[sr][sc]);
        return image;
    }
};