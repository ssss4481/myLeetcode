#include <vector>
#include <string>
#include <iostream>
#include "TreeNode.hpp"

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Codec {//same as 297
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string s = "";
        if(root == nullptr){
            return s;
        }
        std::queue<TreeNode*> Q1;

        Q1.push(root);
        bool valid_node = true;
        while(!Q1.empty() && valid_node){
            std::queue<TreeNode*> Q2;
            valid_node = false;
            const int n = Q1.size();
            for(int i = 1; i <= n; ++i){
                auto pNode = Q1.front();
                if(pNode == nullptr){
                    s += ",n";
                }else{
                    s += ",";
                    s += std::to_string(pNode->val);
                    if(pNode->left != nullptr || pNode->right != nullptr){
                        valid_node = true;
                    }
                    Q2.push(pNode->left);
                    Q2.push(pNode->right);
                }
                Q1.pop();
            }
            Q1.swap(Q2);
        }
        while(s.back() == 'n'){
            s.pop_back();
            s.pop_back();
        }
        return s.substr(1);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if(data == ""){
            return nullptr;
        }
        int lo = 0;
        int hi = 1;
        while(hi < data.size() && data[hi] != ','){
            ++hi;
        }

        std::vector<TreeNode*> nodes;
        while(hi < data.size()){
            if(data[hi] != ','){
                ++hi;
                continue;
            }
            if(data[lo] == 'n'){
                nodes.push_back(nullptr);
            }else{
                std::string node_val = data.substr(lo, hi-lo);
                nodes.push_back(new TreeNode(stoi(node_val)));
            }
            lo = hi+1;
            ++hi;
        }
        
        std::string node_val = data.substr(lo, hi-lo);
        if(node_val != "n"){
            nodes.push_back(new TreeNode(stoi(node_val)));
        }

        connect_nodes(nodes);
        return nodes[0];
    }

    void connect_nodes(std::vector<TreeNode*>& nodes){
        int parent_start = 0;
        int count = 2;
        int child_start = 1;
        
        while(child_start < nodes.size()){
            int parent_cur = parent_start;
            int child_cur = child_start;
            while (parent_cur < child_start && child_cur < nodes.size()){
                if(nodes[parent_cur] == nullptr){
                    ++parent_cur;
                    continue;
                }
                nodes[parent_cur]->left = nodes[child_cur++];
                if(child_cur < nodes.size()){
                    nodes[parent_cur]->right = nodes[child_cur++];
                }
                ++parent_cur;
            }
            parent_start = child_start;
            child_start = child_cur;
        }
    }

};