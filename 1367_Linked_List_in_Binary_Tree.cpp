#include <iostream>
#include <string>
#include "ListNode.hpp"
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        string liststr = to_string(head->val);
        head = head->next;
        while(head != nullptr){
            liststr += ("," + to_string(head->val));
            head = head->next;
        }
        string path = "";
        return trace(liststr, path, root);
    }

    bool trace(const string& liststr, string& path, TreeNode* root){

        if(root == nullptr){
            return path.find(liststr) != string::npos;
        }
        
        string val_str = to_string(root->val);

        if(path == ""){
            path = val_str;
        }else{
            path += ("," + val_str);
        }

        bool found = trace(liststr, path, root->left) || trace(liststr, path, root->right);

        if(!found){
            for(auto& c: val_str){
                path.pop_back();
            }
            if(path.size() > 0){
                path.pop_back();
            }
        }

        return found;
    }
};