#include <climits>
#include <cstdlib>
#include <vector>
#include "TreeNode.hpp"

class Solution 
{    
private:
    int ans;
    std::vector<int> sortedArr;

public:
    void LDR(TreeNode* node)
    {
        if(node == nullptr)
            return;
        
        LDR(node->left);
        this->sortedArr.push_back(node->val);
        LDR(node->right);
    }
  
    int getMinimumDifference(TreeNode* root) 
    {
        this->ans = INT_MAX;
        
        LDR(root);

        for(int i = 1; i < sortedArr.size(); ++i)
        {
            if(sortedArr[i] - sortedArr[i-1] < this->ans)
                this->ans = sortedArr[i] - sortedArr[i-1];
        }
        return this->ans;        
    }
};