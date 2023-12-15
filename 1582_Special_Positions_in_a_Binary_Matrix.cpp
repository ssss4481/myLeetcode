#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    int numSpecial(std::vector<std::vector<int>>& mat) 
    {
        std::vector<int> m(mat.size());
        std::vector<int> n(mat[0].size());        
        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 1)
                {
                    ++m[i];
                    ++n[j];
                }
            }
        }
        int ret = 0;

        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 1 && m[i] == 1 && n[j] == 1)
                {
                    ++ret;
                }
            }
        }
        return ret;        
    }
};


class Solution 
{
public:
    int numSpecial(std::vector<std::vector<int>>& mat) 
    {
        std::unordered_map<int, std::vector<int>> m_to_n;
        std::unordered_map<int, std::vector<int>> n_to_m;
        for(int i = 0; i < mat.size(); ++i)
        {
            for(int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 1)
                {
                    m_to_n[i].push_back(j);
                    n_to_m[j].push_back(i);
                }
            }
        }
        int ret = 0;
        for(auto& p: m_to_n)
        {
            if(p.second.size() == 1 && n_to_m[p.second[0]].size() == 1)
            {
                ++ret;
            }
        }
        return ret;        
    }
};