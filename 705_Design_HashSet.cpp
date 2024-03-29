#include <memory>
#include <vector>
#include <assert.h> 


class MyHashMap 
{
public:
    vstd::ector<int> table;

    MyHashMap() 
    {
        this->
        
    }
    
    void put(int key, int value) 
    {
        this->table[key] = value;
        
    }
    
    int get(int key) 
    {
        return this->table[key];        
    }
    
    void remove(int key) 
    {
        this->table[key] = -1;        
    }
};





enum CHILD
{
    toLeft,
    toRight
};

class BSTNode
{
private:
    bool isLeftChild;
    std::unique_ptr<BSTNode> left;
    std::unique_ptr<BSTNode> right;
    BSTNode* parent;
    int val;// == -1 will be the root.

public:
    BSTNode(int val)
    {
        this->isLeftChild = false;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->val = val;
    }

    BSTNode(int val, BSTNode* parent)
    {
        this->isLeftChild = (val < parent->val);
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
        this->val = val;
    }

    void insert(const int& val)
    {
        if(val == this->val)
            return;

        if(val < this->val)
        {
            if(this->left == nullptr)
                this->left = std::make_unique<BSTNode>(val, this);
            else
                this->left->insert(val);
        }
        else
        {
            if(this->right == nullptr)
                this->right = std::make_unique<BSTNode>(val, this);
            else
                this->right->insert(val);         
        }
    }

    void remove(const int& val)
    {
        BSTNode* target = this->findNode(val);
        
        if(target == nullptr)
            return;
        
        if(target->left.get() != nullptr && target->right.get() != nullptr)//target has two child.
        {
            BSTNode* newValNode = target->left.get();
            
            while(newValNode->right.get() != nullptr)
                newValNode = newValNode->right.get();
            
            target->val = newValNode->val;

            if(newValNode->parent == target)            
                target->left = std::move(newValNode->left);            
            else            
                newValNode->parent->right = std::move(newValNode->left);
            
            return;         
        }

        if(target->left.get() == nullptr && target->right.get() == nullptr)//target is a leaf
        {
            if(target->isLeftChild)
                target->parent->left.reset();
            else
                target->parent->right.reset();
            return;
        }

        //Below this line, the target is not a leaf. It has exact only one child.
        if(target->isLeftChild)        
            this->replaceOneChildNode(target, toLeft);        
        else//target is right child
            this->replaceOneChildNode(target, toRight);

    }
    
    BSTNode* findNode(const int& val)
    {        
        if(this->val == val)
            return this; 

        if(val < this->val && this->left != nullptr)                 
            return this->left->findNode(val);        
        
        if(this->right != nullptr)
            return this->right->findNode(val);

        return nullptr;
    }

    void replaceOneChildNode(BSTNode* target, int mode)
    {
        assert(target->left.get() != nullptr || target->right.get() != nullptr);

        std::unique_ptr<BSTNode> childForReplacement = (target->left.get() != nullptr ? std::move(target->left) : std::move(target->right));           

        childForReplacement->parent = target->parent;

        if(mode == toLeft)          
            target->parent->left = std::move(childForReplacement);       
        else
            target->parent->right = std::move(childForReplacement); 

    }

    bool contains(const int& val)
    {
        return this->findNode(val) != nullptr;
    }
};


class MyHashSet {
private:
    const int hashKey = 901;
    std::vector<BSTNode*> hashTable;

public:
    MyHashSet() 
    {
        this->hashTable = std::vector<BSTNode*> (this->hashKey, nullptr);        
    }
    
    void add(int key) 
    {   
        int idx = key % this->hashKey;
        if(this->hashTable[idx] == nullptr)
            this->hashTable[idx] = new BSTNode(-1);//root of the BST
        this->hashTable[idx]->insert(key);        
    }
    
    void remove(int key)
    { 
        int idx = key % this->hashKey;
        if(this->hashTable[idx] == nullptr)
            return;
        this->hashTable[idx]->remove(key);       
    }
    
    bool contains(int key) 
    {
        int idx = key % this->hashKey;
        if(this->hashTable[idx] == nullptr)
            return false;
        return this->hashTable[idx]->contains(key);        
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
