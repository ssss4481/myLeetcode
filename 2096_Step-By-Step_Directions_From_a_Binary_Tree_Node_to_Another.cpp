#include <string>
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
public:
    string toStart;
    string toDest;

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string current = "";
        trace(root, startValue, destValue, current);

        int prefix_idx = 0;

        while(prefix_idx < min(this->toStart.size(), this->toDest.size()) && this->toStart[prefix_idx] == this->toDest[prefix_idx]){
            ++prefix_idx;
        }

        if(prefix_idx == this->toStart.size()){
            return this->toDest.substr(prefix_idx);
        }else if(prefix_idx == this->toDest.size()){
            return string(this->toStart.size() - this->toDest.size(), 'U');
        }

        return string(this->toStart.size() - prefix_idx, 'U') + this->toDest.substr(prefix_idx);
    }

    void trace(TreeNode* root, const int startValue, const int destValue, string& current){
        if(root == nullptr){
            return;
        }

        if(root->val == startValue){
            this->toStart = current;
        }else if(root->val == destValue){
            this->toDest = current;
        }

        current.push_back('L');
        trace(root->left, startValue, destValue, current);
        current.pop_back();

        current.push_back('R');
        trace(root->right, startValue, destValue, current);
        current.pop_back();

    }
};