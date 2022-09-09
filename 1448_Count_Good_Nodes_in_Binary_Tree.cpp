#include <iostream>
#include "TreeNode.hpp"

using namespace std;

void trace(const TreeNode* &pNode, int &ret, int max)
{
    if(pNode == nullptr)
        return;

    if(pNode->val >= max)
    {
        ++ret;
        max = pNode->val;
    }
    trace(pNode->left, ret, max);
    trace(pNode->right, ret, max);
    return;
}

int goodNodes(const TreeNode* &root)
{
    int ret = 0;
    int max = root->val;
    trace(root, ret, max);
    return ret;
}