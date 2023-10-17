#include <vector>
#include <iostream>

class Solution 
{
public:
    std::vector<int> getRow(int rowIndex) 
    {
        if(rowIndex == 0)
        {
            return {1};
        }

        if(rowIndex == 1)
        {
            return {1, 1};
        }
        std::vector<int> base = {1, 1};
        std::vector<int> ret = base;
        auto nextRow = [&]()
        {
            ret.push_back(1);
            const int iLimit = ret.size()-1;
            for(int i = 1; i < iLimit; ++i)
            {
                ret[i] = base[i-1]+base[i];
            }
        };
        for(int i = 2; i <= rowIndex; ++i)        
        {
            nextRow();
            base = ret;
        }
        return ret;        
    }
};