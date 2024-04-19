#include <queue>
#include "TreeNode.hpp"

typedef std::pair<TreeNode*, long long> pi;//node and number

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        std::queue<pi> Q;
        Q.push({root, 1});
        long long width = 1;
        while(!Q.empty()){
            std::queue<pi> Q2;
            long long minNode = Q.front().second;
            long long maxNode = minNode;
            while(!Q.empty()){
                auto p = Q.front();
                if(p.first->left != nullptr){
                    Q2.push({p.first->left, 2*(p.second-minNode)+1});
                }
                if(p.first->right != nullptr){
                    Q2.push({p.first->right, 2*(p.second-minNode)+2});
                }
                maxNode = std::max(maxNode, p.second);
                Q.pop();
            }
            width = std::max(width, maxNode-minNode+1);
            Q.swap(Q2);
        }
        return static_cast<int>(width);
    }
};