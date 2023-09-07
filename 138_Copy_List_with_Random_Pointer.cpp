#include <unordered_map>

class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution 
{
public:   
    Node* copyRandomList(Node* head) 
    {
        if(head == nullptr)
        {
            return nullptr;
        }

        std::unordered_map<Node*, Node*> nodeMap;

        Node* pHeadNode = head;       
        Node* pCopyHeadNode = new Node(head->val);
        Node* pWorkCopyNode = pCopyHeadNode;

        nodeMap[nullptr] = nullptr;
        nodeMap[head] = pCopyHeadNode;
        pHeadNode = pHeadNode->next;
        
        while(pHeadNode != nullptr)
        {
            pWorkCopyNode->next = new Node(pHeadNode->val);
            pWorkCopyNode = pWorkCopyNode->next;
            nodeMap[pHeadNode] = pWorkCopyNode;
            pHeadNode = pHeadNode->next;
        }

        pWorkCopyNode = pCopyHeadNode;
        while(head != nullptr)
        {
            pWorkCopyNode->random = nodeMap[head->random];
            pWorkCopyNode = pWorkCopyNode->next;
            head = head->next;
        }
        return pCopyHeadNode;       
    }
};