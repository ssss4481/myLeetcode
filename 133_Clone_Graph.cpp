#include <unordered_map>
#include <vector>
#include <iostream>


class Node 
{
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
private:
    std::unordered_map<Node*, Node*> originToCopy;

public:
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr)
        {
            return nullptr;
        }

        this->clone(node);
        return this->originToCopy[node];
    }

    void clone(Node* pNode)
    {
        if(this->originToCopy.count(pNode))
        {
            return;
        }
        auto p = new Node(pNode->val);
        this->originToCopy[pNode] = p;
        for(auto& next: pNode->neighbors)
        {
            this->clone(next);
            p->neighbors.push_back(this->originToCopy[next]);
        }
    }
};