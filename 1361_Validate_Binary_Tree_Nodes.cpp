#include <vector>
#include <iostream>
#include <numeric>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);
    return 0;
}();


class Solution 
{
public:
    bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) 
    {
        std::vector<int> parentInfo(n, -1);
        auto checkParent = [&](std::vector<int>& childInfo)
        {
            for(int i = 0; i < n; ++i)
            {
                if(childInfo[i] != -1)
                {
                    if(parentInfo[childInfo[i]] != -1)
                    {
                        return false;
                    }
                    parentInfo[childInfo[i]] = i;
                }
            }
            return true;
        };

        if(!checkParent(leftChild))
        {
            return false;
        }

        if(!checkParent(rightChild))
        {
            return false;
        }

        std::vector<char> visit(n, 0);
        for(int i = 0; i < n; ++i)
        {            
            if(parentInfo[i] == -1)//should be root
            {                
                DFS(visit, i, leftChild, rightChild);
                for(char& val:visit)
                {
                    if(val == 0)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }   

    void DFS(std::vector<char>& visit, int node, std::vector<int>& leftChild, std::vector<int>& rightChild)
    {
        if(node == -1 || visit[node])
        {
            return;
        }
        visit[node] = 1;
        DFS(visit, leftChild[node], leftChild, rightChild);
        DFS(visit, rightChild[node], leftChild, rightChild);
    }        
};