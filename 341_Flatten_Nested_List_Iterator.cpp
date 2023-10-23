#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>


  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
class NestedInteger 
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};


class NestedIterator //cheat
{
public:
    std::vector<int> res;
    int resIdx;    

    NestedIterator(std::vector<NestedInteger> &nestedList) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
        this->res = std::vector<int> ();
        this->resIdx = 0;
        digInt(nestedList);
    }

    void digInt(std::vector<NestedInteger>& nestedList)
    {
        for(auto& nI: nestedList)
        {
            if(nI.isInteger())
            {
                this->res.push_back(nI.getInteger());
            }
            else
            {
                auto vec = nI.getList();
                this->digInt(vec);
            }
        }
    }

    int next() 
    {   
        return res[resIdx++];
    }

    bool hasNext() 
    {
        return resIdx < res.size();
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */