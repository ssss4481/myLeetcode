#include <vector>
#include "TreeNode.hpp"

using namespace std;




void Trace(TreeNode* pNode, const int &level, vector<int> &NodeCount, vector<double> &NodeSumByLevel)
{
    if(pNode == nullptr)
        return;

    if(level == NodeCount.size())
    {
        NodeCount.push_back(1);
        NodeSumByLevel.push_back(pNode->val);
    }
    else
    {
        ++NodeCount[level];
        NodeSumByLevel[level] += pNode->val;
    }
    Trace(pNode->left, level+1, NodeCount, NodeSumByLevel);
    Trace(pNode->right, level+1, NodeCount, NodeSumByLevel);

}

vector<double> averageOfLevels(TreeNode* root)
{
    vector<int> NodeCount;
    vector<double> NodeSumByLevel;

    Trace(root, 0, NodeCount, NodeSumByLevel);

    for(int i = 0; i < NodeCount.size(); ++i)
    {
        NodeSumByLevel[i] /= NodeCount[i];
    }

    return NodeSumByLevel;

}