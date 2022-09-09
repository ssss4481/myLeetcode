#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#include "Matrix.hpp"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    static bool my_sort(const pair<int, int> &a,
                        const pair<int, int> &b)
    {
        if(a.first == b.first)
        {
            return (a.second < b.second);
        }
        return (a.first < b.first);
    }

    //pair(deep, val)
    void Traversal(TreeNode* pNode,
                    int position,
                    int deep ,
                    map<int, vector<pair<int, int>> > &mapping)
    {
        if(pNode == nullptr)
            return;

        if(mapping.count(position) > 0)
        {
            mapping[position].push_back(make_pair(deep, pNode->val));
        }
        else
        {
            mapping[position] = {make_pair(deep, pNode->val)};
        }

        Traversal(pNode->left, position-1, deep + 1, mapping);
        Traversal(pNode->right, position+1, deep + 1, mapping);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        map<int, vector< pair<int, int> > > mapping;
        vector< vector<int> >                   ret;

        Traversal(root, 0, 0, mapping);

        for(map<int, vector< pair<int, int> > >::iterator it = mapping.begin(); it != mapping.end(); ++it)
        {
            sort(it->second.begin(), it->second.end(), Solution::my_sort);
            vector<int> temp (it->second.size(), 0);
            for(int i = 0; i < it->second.size(); ++i)
            {
                temp[i] = it->second[i].second;
            }
            ret.push_back(temp);
        }

        return ret;
    }
};


static bool my_sort(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    return (a.first < b.first);
}

//pair(deep, val)
void Traversal(TreeNode* pNode, int position, int deep ,map<int, vector<pair<int, int>> > &mapping)
{
    if(pNode == nullptr)
        return;
    if(mapping.count(position) > 0)
    {
        mapping[position].push_back(make_pair(deep, pNode->val));
    }
    else
    {
        mapping[position] = {make_pair(deep, pNode->val)};
    }
    Traversal(pNode->left, position-1, deep + 1, mapping);
    Traversal(pNode->right, position+1, deep + 1, mapping);
}

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    map<int, vector< pair<int, int> > > mapping;
    vector< vector<int> > ret;
    Traversal(root, 0, 0, mapping);
    for(map<int, vector< pair<int, int> > >::iterator it = mapping.begin(); it != mapping.end(); ++it)
    {
        sort(it->second.begin(), it->second.end(), my_sort);
        vector<int> temp (it->second.size(), 0);
        for(int i = 0; i < temp.size(); ++i)
        {
            temp[i] = it->second[i].second;
        }
        ret.push_back(temp);
    }
    return ret;
}

int main()
{
    return 0;
}