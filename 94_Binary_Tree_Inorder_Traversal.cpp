//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void trace(TreeNode* pNode, vector<int> &ret)
    {
        if(pNode == nullptr)
            return;
        trace(pNode->left, ret);
        ret.push_back(pNode->val);
        trace(pNode->right, ret);

    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        trace(root, ret);
        return ret;
    }
};