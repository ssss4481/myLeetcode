#include <unordered_map>
#include "TreeNode.hpp"


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {

        std::unordered_map<long long, int> prefixsumAndCount;
        prefixsumAndCount[0] = 1;
        return DFS(root, static_cast<long long>(targetSum), 0LL, prefixsumAndCount);
    }

    int DFS(TreeNode* pNode, const long long& targetSum, long long currentSum, std::unordered_map<long long, int>& prefixsumAndCount){
        if(pNode == nullptr){
            return 0;
        }
        currentSum += pNode->val;
        int res = prefixsumAndCount[currentSum - targetSum];
        ++prefixsumAndCount[currentSum];
        res += DFS(pNode->left, targetSum, currentSum, prefixsumAndCount);
        res += DFS(pNode->right, targetSum, currentSum, prefixsumAndCount);
        --prefixsumAndCount[currentSum];
        return res;
    }
};


class Solution1 {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return 0;
        }
        return alongSum(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int alongSum(TreeNode* pNode, int prevSum, const int& targetSum){
        if(pNode == 0){
            return 0;
        }
        int ret = 0;
        long long cur = prevSum + pNode->val;
        if(cur == targetSum){
            ++ret;
        }
        ret += alongSum(pNode->left, cur, targetSum) + alongSum(pNode->right, cur, targetSum);
        return ret;
    }
};




class Solution2 {//Too Slow
public:
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<TreeNode*, std::unordered_map<long long, int>> dp;
        dp[nullptr][0] = 0;
        int totalCount = 0;
        trace(root, dp, targetSum, totalCount);
        return totalCount;
    }

    void trace(TreeNode* pNode, std::unordered_map<TreeNode*, std::unordered_map<long long, int>>& dp, const int& targetSum, int& totalCount){
        if(pNode == nullptr){
            return;
        }
        trace(pNode->left, dp, targetSum, totalCount);
        trace(pNode->right, dp, targetSum, totalCount);

        if(pNode->left != nullptr){
            totalCount += dp[pNode->left][targetSum - pNode->val];
            for(auto& p: dp[pNode->left]){
                const long long& value = p.first;
                const int& count = p.second;
                dp[pNode][pNode->val + value] += count;
            }
            dp.erase(pNode->left);
        }

        if(pNode->right != nullptr){
            totalCount += dp[pNode->right][targetSum - pNode->val];
            for(auto& p: dp[pNode->right]){
                const long long& value = p.first;
                const int& count = p.second;
                dp[pNode][pNode->val + value] += count;
            }
            dp.erase(pNode->right);
        }
        ++dp[pNode][pNode->val];
        if(pNode->val == targetSum){
            ++totalCount;
        }
    }
};