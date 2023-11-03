#include <vector>
#include <algorithm>
#include <unordered_map>
#include "TreeNode.hpp"


class Solution 
{
public:
    int currentVal;
    int maxCount;
    std::unordered_map<int, int> map;
    
    std::vector<int> findMode(TreeNode* root)     
    {
        this->currentVal = 100001;
        this->maxCount = 0;        
        LDR(root);
        this->maxCount = std::max(this->map[this->currentVal], this->maxCount);
        std::vector<int> ans;
        for(auto& p: map)
        {
            if(p.second == this->maxCount)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }

    void LDR(TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return;
        }
        LDR(pNode->left);
        ++this->map[pNode->val];
        if(pNode->val != this->currentVal)
        {           
            this->maxCount = std::max(this->map[this->currentVal], this->maxCount);
            this->currentVal = pNode->val;        
        }
        LDR(pNode->right);
    }
};


class Solution2 
{
public:
    int currentVal;
    int currentCount;
    int maxCount;
    std::vector<int> values;

    std::vector<int> findMode(TreeNode* root)     
    {
        this->currentVal = 1000000;
        this->currentCount = 0;
        this->maxCount = 0;
        LDR(root);
        this->maxCount = std::max(this->maxCount, this->currentCount);
        std::vector<int> ans;   
        this->currentVal = this->values[0];
        this->currentCount = 0;
        for(int& num:values)
        {
            if(num == this->currentVal)
            {
                ++this->currentCount;
            }
            else
            {
                if(this->currentCount == this->maxCount)
                {
                    ans.push_back(this->currentVal);
                }
                this->currentVal = num;
                this->currentCount = 1;
            }
        }
        if(this->currentCount == this->maxCount)
        {
            ans.push_back(this->currentVal);
        }
        return ans;
    }

    void LDR(TreeNode* pNode)
    {
        if(pNode == nullptr)
        {
            return;
        }
        LDR(pNode->left);
        if(this->currentVal == pNode->val)
        {
            ++this->currentCount;
        }
        else
        {
            this->maxCount = std::max(this->maxCount, this->currentCount);
            this->currentVal = pNode->val;
            this->currentCount = 1;
        }        
        this->values.push_back(pNode->val);
        LDR(pNode->right);
    }
};