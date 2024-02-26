#include <vector>
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
    int findJudge(int n, std::vector<std::vector<int>>& trust) 
    {
        std::vector<int> inorder (n+1, 0);
        std::vector<int> outorder (n+1, 0);

        for(auto& t : trust)
        {
            ++inorder[t[1]];
            ++outorder[t[0]];
        }

        int allTrustPerson = 0;
        int allTrustPersonCount = 0;
        for(int i = 1; i < n+1; ++i)
        {
            if(inorder[i] == n-1)
            {
                if(outorder[i] != 0)
                {
                    return -1;
                }
                allTrustPerson = i;                
                ++allTrustPersonCount;
            }
        }

        return allTrustPersonCount == 1 ? allTrustPerson : -1;

    }
};