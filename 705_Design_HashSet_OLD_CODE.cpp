#include <memory>
#include <vector>

class BSTNode
{
private:
    bool isLeftChild;
    std::unique_ptr<BSTNode> left;
    std::unique_ptr<BSTNode> right;
    BSTNode* parent;
    int val;

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

    BSTNode* findNode(const int& val)
    {        
        if(this->val == val)
            return this;
        
        if(val < this->val)
        {          
            if(this->left == nullptr)
                return nullptr;            
            return this->left->findNode(val);
        }
        else
        {   
            if(this->right == nullptr)
                return nullptr;            
            return this->right->findNode(val);
        }
    }

    void remove(const int& val)
    {
        BSTNode* target = this->findNode(val);
        
        if(target == nullptr)
            return;
        
        if(target->left.get() != nullptr && target->right.get() != nullptr)
        {
            BSTNode* newValNode = target->left.get();
            
            while(newValNode->right.get() != nullptr)
                newValNode = newValNode->right.get();
            
            target->val = newValNode->val;

            if(newValNode->parent == target)
            {
                target->left = std::move(newValNode->left);
            }
            else
            {
                newValNode->parent->right = std::move(newValNode->left);
            }
            return;         
        }

        if(target->left.get() == nullptr && target->right.get() == nullptr)
        {
            if(target->isLeftChild)
                target->parent->left.reset();
            else
                target->parent->right.reset();
            return;
        }


        if(target->isLeftChild)
        {
            if(target->left.get() != nullptr)
            {
                target->left->parent = target->parent;
                target->parent->left = std::move(target->left);
            }
            else
            {
                target->right->parent = target->parent;
                target->parent->left = std::move(target->right);
            }           

        }
        else
        {
            if(target->left.get() != nullptr)
            {
                target->left->parent = target->parent;
                target->parent->right = std::move(target->left);
            }
            else
            {
                target->right->parent = target->parent;
                target->parent->right = std::move(target->right);
            }         
        }  

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
            this->hashTable[idx] = new BSTNode(-1);
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
