#include <vector>
#include <algorithm>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        if(target < matrix.front().front() || target > matrix.back().back())
        {
            return false;
        }
        int i = verticalSearch(matrix, target, 0, static_cast<int>(matrix.size()-1));

        auto pLB = std::lower_bound(matrix[i].begin(), matrix[i].end(), target);
        if(pLB != matrix[i].end() && *pLB == target)
        {
            return true;
        }
        return false;
    }

    int verticalSearch(std::vector<std::vector<int>>& matrix, const int& target, int lo, int hi)
    {
        if(lo == hi)
        {
            return lo;
        }

        if(lo+1 == hi)
        {
            if(matrix[hi].front() <= target)
            {
                return hi;
            }
            return lo;
        }

        int mid = (lo + hi)/2;

        if(matrix[mid].front() == target)
        {
            return mid;
        }
        else if(matrix[mid].front() > target)
        {
            return verticalSearch(matrix, target, lo, mid);
        }
        else
        {
            return verticalSearch(matrix, target, mid, hi);
        }
    }
};