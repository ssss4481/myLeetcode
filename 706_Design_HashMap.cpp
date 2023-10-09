#include <vector>
#include <iostream>

static const int n = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


class MyHashMap 
{
public:
    std::vector<int> table;

    MyHashMap() 
    {
        this->table = std::vector<int> (1000001, -1);
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
    int key;// == -1 will be the root.
    int value;

public:
    BSTNode(int key)
    {
        this->isLeftChild = false;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->key = key;
    }

    BSTNode(int key, int value, BSTNode* parent)
    {
        this->isLeftChild = (key < parent->key);
        this->left = nullptr;
        this->right = nullptr;
        this->parent = parent;
        this->key = key;
        this->value = value;
    }

    int getValue()
    {
        return this->value;
    }

    void insert(const int& key, const int& value)
    {
        if(key == this->key)
        {
            this->value = value;
            return;
        }

        if(key < this->key)
        {
            if(this->left == nullptr)
            {
                this->left = std::make_unique<BSTNode>(key, value, this);
            }
            else
            {
                this->left->insert(key, value);
            }
        }
        else
        {
            if(this->right == nullptr)
            {
                this->right = std::make_unique<BSTNode>(key, value, this);
            }
            else
            {
                this->right->insert(key, value);         
            }
        }
    }

    void remove(const int& key)
    {
        BSTNode* target = this->findNode(key);
        
        if(target == nullptr)
        {
            return;
        }
        
        if(target->left.get() != nullptr && target->right.get() != nullptr)//target has two child.
        {
            BSTNode* newValNode = target->left.get();
            
            while(newValNode->right.get() != nullptr)
            {
                newValNode = newValNode->right.get();
            }
            
            target->key = newValNode->key;

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

        if(target->left.get() == nullptr && target->right.get() == nullptr)//target is a leaf
        {
            if(target->isLeftChild)
            {
                target->parent->left.reset();
            }
            else
            {
                target->parent->right.reset();
            }                
            return;
        }

        //Below this line, the target is not a leaf. It has exact only one child.
        if(target->isLeftChild)
        {
            this->replaceOneChildNode(target, toLeft);        
        }
        else//target is right child
        {
            this->replaceOneChildNode(target, toRight);
        }
    }
    
    BSTNode* findNode(const int& key)
    {        
        if(this->key == key)
        {
            return this; 
        }

        if(key < this->key && this->left != nullptr)
        {
            return this->left->findNode(key);        
        }
        
        if(this->right != nullptr)
        {
            return this->right->findNode(key);
        }

        return nullptr;
    }

    void replaceOneChildNode(BSTNode* target, int mode)
    {
        assert(target->left.get() != nullptr || target->right.get() != nullptr);

        std::unique_ptr<BSTNode> childForReplacement = (target->left.get() != nullptr ? std::move(target->left) : std::move(target->right));           

        childForReplacement->parent = target->parent;

        if(mode == toLeft)
        {
            target->parent->left = std::move(childForReplacement);       
        }          
        else
        {
            target->parent->right = std::move(childForReplacement); 
        }

    }

    // bool contains(const int& key)
    // {
    //     return this->findNode(key) != nullptr;
    // }
};


class MyHashMap
{
private:
    const int hashKey = 901;
    std::vector<BSTNode*> hashTable;

public:
    MyHashMap() 
    {
        this->hashTable = std::vector<BSTNode*> (this->hashKey, nullptr);        
    }
    
    void put(int key, int value) 
    {   
        int idx = key % this->hashKey;
        if(this->hashTable[idx] == nullptr)
        {
            this->hashTable[idx] = new BSTNode(-1);//root of the BST
        }
        this->hashTable[idx]->insert(key, value);
    }
    
    void remove(int key)
    { 
        int idx = key % this->hashKey;
        if(this->hashTable[idx] == nullptr)
        {
            return;
        }
        this->hashTable[idx]->remove(key);       
    }
    
    int get(int key) 
    {
        int idx = key % this->hashKey;
        if(this->hashTable[idx] == nullptr)
        {
            return -1;
        }
        BSTNode* pTargetNode = this->hashTable[idx]->findNode(key);
        if(pTargetNode == nullptr)
        {
            return -1;
        }
        return pTargetNode->getValue();        
    }
};





int main(int argc, char const *argv[])
{
    auto a = MyHashMap();
    a.put(1, 1);
    a.put(2, 2);
    std::cout << a.get(1) << '\n';
    std::cout << a.get(3) << '\n';
    a.put(2, 1);
    std::cout << a.get(2) << '\n';
    a.remove(2);
    std::cout << a.get(2) << '\n'; 

    return 0;
}

