#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


vector<vector<int>> levelOrder(Node* root)
{
    vector< vector<int> > ret;
    if(!root)
        return ret;

    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty())
    {
        vector<int> cur_level;
        int counter = Q.size();
        while(counter--)
        {
            cur_level.push_back(Q.front()->val);
            for(int i = 0; i < Q.front()->children.size(); ++i)
            {
                Q.push(Q.front()->children[i]);
            }
            Q.pop();
        }
        ret.push_back(cur_level);
    }

    return ret;
}


int main()
{


    return 0;
}