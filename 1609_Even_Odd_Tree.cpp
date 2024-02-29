#include <vector>
#include "TreeNode.hpp"
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
    bool isEvenOddTree(TreeNode* root) 
    {
        int level = 0;
        std::vector<TreeNode*> row = {root};
        std::vector<TreeNode*> nextRow;

        auto append = [&nextRow](TreeNode* pNode)
        {
            if(pNode->left != nullptr)
            {
                nextRow.push_back(pNode->left);
            }

            if(pNode->right != nullptr)
            {
                nextRow.push_back(pNode->right);
            }
        };

        auto increasingAndOdd = [append](std::vector<TreeNode*>& row)
        {
            if(row.front()->val % 2 == 0)
            {
                return false;
            }

            append(row[0]);

            for(int i = 1; i < row.size(); ++i)
            {
                if(row[i]->val % 2 == 0 || row[i]->val <= row[i-1]->val)
                {
                    return false;
                }
                append(row[i]);
            }
            return true;
        };

        auto decreasingAndEven = [append](std::vector<TreeNode*>& row)
        {
            if(row.front()->val % 2 != 0)
            {
                return false;
            }

            append(row[0]);

            for(int i = 1; i < row.size(); ++i)
            {
                if(row[i]->val % 2 != 0 || row[i]->val >= row[i-1]->val)
                {
                    return false;
                }
                append(row[i]);
            }
            return true;
        };


        while(!row.empty())
        {
            if(level % 2 == 0)
            {
                if(!increasingAndOdd(row))
                {
                    return false;
                }
            }
            else
            {
                if(!decreasingAndEven(row))
                {
                    return false;
                }
            }
            row.swap(nextRow);
            nextRow.clear();
            ++level;
        }

        return true;
    }
};


class Solution1 //slow
{
public:
    std::vector<std::vector<int>> data;

    bool isEvenOddTree(TreeNode* root) 
    {
        auto decreasingAndEven = [](std::vector<int>& level)
        {
            if(level[0] % 2 != 0)
            {
                return false;
            }

            for(int i = 1; i < level.size(); ++i)
            {
                if(level[i] >= level[i-1] || level[i] % 2 != 0)
                {
                    return false;
                }
            }
            return true;
        };

        auto increasingAndOdd = [](std::vector<int>& level)
        {
            if(level[0] % 2 == 0)
            {
                return false;
            }

            for(int i = 1; i < level.size(); ++i)
            {
                if(level[i] <= level[i-1] || level[i] % 2 == 0)
                {
                    return false;
                }
            }
            return true;
        };


        trace(root, 0);
        for(int i = 0; i < this->data.size(); ++i)
        {
            if(i % 2 == 0)
            {
                if(!increasingAndOdd(data[i]))
                {
                    return false;
                }
            }
            else
            {
                if(!decreasingAndEven(data[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }

    void trace(TreeNode* pNode, int level)
    {
        if(pNode == nullptr)
        {
            return;
        }

        if(this->data.size() <= level)
        {
            data.push_back({});
        }
        data[level].push_back(pNode->val);

        trace(pNode->left, level+1);
        trace(pNode->right, level+1);
    }


};