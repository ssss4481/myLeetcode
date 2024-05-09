#include <vector>
#include <iostream>
#include "TreeNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
private:
    TreeNode* violation1;
    TreeNode* violation2;

public:
    void recoverTree(TreeNode* root) {
        violation1 = nullptr;
        violation2 == nullptr;
        findPredecessor(root, nullptr);
        swap(violation1->val, violation2->val);
    }

    TreeNode* findPredecessor(TreeNode* pNode, TreeNode* prev){
        TreeNode* pred;
        if(pNode->left != nullptr){
            pred = findPredecessor(pNode->left, prev);
        }else{
            pred = prev;
        }
        if(pred != nullptr && pred->val > pNode->val){
            if(violation1 == nullptr){
                violation1 = pred;
                violation2 = pNode;
            }else{
                violation2 = pNode;
            }
        }
        if(pNode->right != nullptr){
            return findPredecessor(pNode->right, pNode);
        }
        return pNode;
    }

};


class Solution1 {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> seq;
        LDRtrace(root, seq);
        TreeNode* swp1 = nullptr;
        TreeNode* swp2 = nullptr;
        int k = 0;
        for(int i = 0; i < seq.size()-1; ++i){
            if(seq[i]->val > seq[i+1]->val){
                if(swp1 == nullptr){
                    swp1 = seq[i];
                    k = i;
                }else{
                    swp2 = seq[i+1];
                    break;
                }
            }
        }
        if(swp2 == nullptr){
            swap(swp1->val, seq[k+1]->val);
        }else{
            swap(swp1->val, swp2->val);
        }
    }


    void LDRtrace(TreeNode* pNode, vector<TreeNode*>& seq){
        if(pNode == nullptr){
            return;
        }
        LDRtrace(pNode->left, seq);
        seq.push_back(pNode);
        LDRtrace(pNode->right, seq);
    }
};