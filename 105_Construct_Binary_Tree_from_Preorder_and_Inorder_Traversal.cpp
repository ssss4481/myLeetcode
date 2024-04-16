#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include "TreeNode.hpp"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int, int> ValueToInorderIdx;
        for(int i = 0; i < inorder.size(); ++i){
            ValueToInorderIdx[inorder[i]] = i;
        }
        int index = 0;
        return recursiveBuild(preorder, ValueToInorderIdx, index, 0, inorder.size()-1);
    }

    TreeNode* recursiveBuild(vector<int>& preorder, std::unordered_map<int, int>& ValueToInorderIdx, int& index, int lo, int hi){
        if(lo > hi){
            return nullptr;
        }
        
        auto currentNode = new TreeNode(preorder[index++]);

        int mid = ValueToInorderIdx[currentNode->val];

        currentNode->left = recursiveBuild(preorder, ValueToInorderIdx, index, lo, mid-1);
        currentNode->right = recursiveBuild(preorder, ValueToInorderIdx, index, mid+1, hi);

        return currentNode;
    }
};



class Solution2 {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        std::unordered_map<int, int> ValueToInorderIdx;
        for(int i = 0; i < inorder.size(); ++i){
            ValueToInorderIdx[inorder[i]] = i;
        }
        int rootIndexOfInorder = ValueToInorderIdx[preorder[0]];
        int Lsize = rootIndexOfInorder;
        int Rsize = inorder.size()-rootIndexOfInorder-1;
        return recursiveBuild(preorder, 0, ValueToInorderIdx, Lsize, Rsize);
    }

    TreeNode* recursiveBuild(std::vector<int>& preorder, int rootIndexOfPreorder, std::unordered_map<int, int>& ValueToInorderIdx, int Lsize, int Rsize){
        
        auto currentNode = new TreeNode(preorder[rootIndexOfPreorder]);
        int rootIndexOfInorder = ValueToInorderIdx[preorder[rootIndexOfPreorder]];

        if(Lsize > 0){
            int leftChildIdxPreorder = rootIndexOfPreorder+1;
            int leftChildIdxInorder = ValueToInorderIdx[preorder[leftChildIdxPreorder]];
            int LRsize = rootIndexOfInorder-leftChildIdxInorder-1;
            int LLsize = Lsize - 1 - LRsize;
            currentNode->left = recursiveBuild(preorder, leftChildIdxPreorder, ValueToInorderIdx, LLsize, LRsize);
        }

        if(Rsize > 0){
            int rightChildIdxPreorder = rootIndexOfPreorder+Lsize+1;
            int rightChildIdxInorder = ValueToInorderIdx[preorder[rightChildIdxPreorder]];
            int RLsize = rightChildIdxInorder-rootIndexOfInorder-1;
            int RRsize = Rsize - 1 - RLsize;
            currentNode->right = recursiveBuild(preorder, rightChildIdxPreorder, ValueToInorderIdx, RLsize, RRsize);
        }
        return currentNode;
    }
};


class Solution1 {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        int rootIndexOfInorder = static_cast<int>(std::find(inorder.begin(), inorder.end(), preorder[0])-inorder.begin());
        int Lsize = rootIndexOfInorder;
        int Rsize = inorder.size()-rootIndexOfInorder-1;
        return recursiveBuild(preorder, inorder, 0, rootIndexOfInorder, Lsize, Rsize);
    }

    TreeNode* recursiveBuild(std::vector<int>& preorder, std::vector<int>& inorder, int rootIndexOfPreorder, int rootIndexOfInorder, int Lsize, int Rsize){
        
        auto currentNode = new TreeNode(preorder[rootIndexOfPreorder]);

        if(Lsize > 0){
            int leftChildIdxPreorder = rootIndexOfPreorder+1;
            auto it = std::find(inorder.begin(), inorder.begin()+rootIndexOfInorder, preorder[leftChildIdxPreorder]);
            int leftChildIdxInorder = static_cast<int>(it-inorder.begin());
            int LRsize = rootIndexOfInorder-leftChildIdxInorder-1;
            int LLsize = Lsize - 1 - LRsize;
            currentNode->left = recursiveBuild(preorder, inorder, leftChildIdxPreorder, leftChildIdxInorder, LLsize, LRsize);
        }

        if(Rsize > 0){
            int rightChildIdxPreorder = rootIndexOfPreorder+Lsize+1;
            auto it = std::find(inorder.begin()+rootIndexOfInorder+1, inorder.begin()+rootIndexOfInorder+1+Rsize, preorder[rightChildIdxPreorder]);
            int rightChildIdxInorder = static_cast<int>(it-inorder.begin());
            int RLsize = rightChildIdxInorder-rootIndexOfInorder-1;
            int RRsize = Rsize - 1 - RLsize;
            currentNode->right = recursiveBuild(preorder, inorder, rightChildIdxPreorder, rightChildIdxInorder, RLsize, RRsize);
        }
        return currentNode;
    }
};