#include <vector>
#include "TreeNode.hpp"

class Solution {
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        std::vector<TreeNode*> root_to_target;
        bool found = false;
        DFS(root, target, found, root_to_target);

        int i = root_to_target.size()-1;
        std::vector<int> ret_nodes;
        
        while(k >= 0 && i >= 0){
            TreeNode* avoid_path = i < root_to_target.size()-1 ? root_to_target[i+1] : nullptr;
            find_node_with_condition(root_to_target[i], avoid_path, ret_nodes, 0, k);
            --i;
            --k;
        }
        return ret_nodes;
    }

    void DFS(TreeNode* pNode, const TreeNode* target, bool& found, std::vector<TreeNode*>& root_to_target){
        if(pNode == nullptr || found){
            return;
        }
        root_to_target.push_back(pNode);
        if(pNode == target){
            found = true;
            return;
        }

        DFS(pNode->left, target, found, root_to_target);
        DFS(pNode->right, target, found, root_to_target);

        if(!found){
            root_to_target.pop_back();
        }
    }

    void find_node_with_condition(TreeNode* pNode, const TreeNode* avoid_path, std::vector<int>& ret_nodes, int current_depth, const int target_depth){
        if(pNode == nullptr || pNode == avoid_path){
            return;
        }
        if(current_depth == target_depth){
            ret_nodes.push_back(pNode->val);
            return;
        }
        find_node_with_condition(pNode->left, avoid_path, ret_nodes, current_depth+1, target_depth);
        find_node_with_condition(pNode->right, avoid_path, ret_nodes, current_depth+1, target_depth);
    }

};


using namespace std;

class Solution2//Old 
{
private:
    vector<int> ret;
    vector<TreeNode*> targetToRoot;


public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        bool found = false;
        DFS(root, target, found);

        int distance = 0;
        DFSwithDistance(target, nullptr, distance, k);
        for(int i = 1; i < targetToRoot.size(); ++i)
        {
            ++distance;
            DFSwithDistance(targetToRoot[i], targetToRoot[i-1], distance, k);
        }
        return this->ret;
    }

    void DFS(TreeNode* current, TreeNode* target, bool& found)
    {
        if(current == nullptr)
        {
            return;
        }

        if(current == target)
        {
            found = true;
            targetToRoot.push_back(target);
            return;
        }

        DFS(current->left, target, found);
        if(found)
        {
            targetToRoot.push_back(current);
            return;
        }        
        DFS(current->right, target, found);
        if(found)
        {
            targetToRoot.push_back(current);
            return;
        }       
    }

    void DFSwithDistance(TreeNode* current, TreeNode* avoid, int distance, const int& k)
    {
        if(current == nullptr || distance > k || current == avoid)
        {
            return;
        }
        if(distance == k)
        {
            ret.push_back(current->val);
            return;
        }
        DFSwithDistance(current->left, avoid, distance+1, k);
        DFSwithDistance(current->right, avoid, distance+1, k);
    }

};