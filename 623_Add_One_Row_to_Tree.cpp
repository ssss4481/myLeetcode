#include "TreeNode.hpp"

using namespace std;

class Solution {
public:
    void appendNode(TreeNode* pNode, const int &val)
    {
        TreeNode* leftReplacer = new TreeNode(val, pNode->left, nullptr);
        TreeNode* rightReplacer = new TreeNode(val, nullptr, pNode->right);
        pNode->left = leftReplacer;
        pNode->right = rightReplacer;
    }

    TreeNode* specialCase(TreeNode* pNode, const int &val)
    {
        TreeNode* newRoot = new TreeNode(val, pNode, nullptr);
        return newRoot;
    }

    void trace(TreeNode* pNode, const int &val, int curDepth, const int& targetDepth)
    {
        if(pNode == nullptr)
            return;
        if(curDepth == targetDepth)
        {
            appendNode(pNode, val);
            return;
        }
        trace(pNode->left, val, curDepth+1, targetDepth);
        trace(pNode->right, val, curDepth+1, targetDepth);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if(depth == 1)
        {
            return specialCase(root, val);
        }

        trace(root, val, 1, depth-1);
        return root;
    }
};

int main()
{

    return 0;

}