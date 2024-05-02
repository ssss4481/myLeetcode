#include <stack>
#include "TreeNode.hpp"


class BSTIterator {
private:
    std::stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        while(root != nullptr){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* pNode = st.top();
        int val = pNode->val;
        st.pop();
        pNode = pNode->right;
        if(pNode != nullptr){
            st.push(pNode);
            pNode = pNode->left;
            while(pNode != nullptr){
                st.push(pNode);
                pNode = pNode->left;
            }            
        }
        return val;
    }

    bool hasNext() {
        return !st.empty();
    }
};