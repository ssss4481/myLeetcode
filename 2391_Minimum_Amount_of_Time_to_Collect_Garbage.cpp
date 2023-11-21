#include <vector>
#include <iostream>


static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();


#define __M__ 0
#define __P__ 1
#define __G__ 2


class Solution 
{
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) 
    {
        const int n = garbage.size();
        int finalStop[4] {0};        
        int garbageCount[4] {0};

        for(int i = 0 ; i < n; ++i)
        {
            for(auto& c : garbage[i])
            {
                switch (c)
                {
                    case 'M':
                        ++garbageCount[__M__];
                        finalStop[__M__] = i;
                        break;
                    case 'P':
                        ++garbageCount[__P__];
                        finalStop[__P__] = i;
                        break;     
                    case 'G':
                        ++garbageCount[__G__];
                        finalStop[__G__] = i;
                        break;                                                                     
                    default:
                        break;
                }
            }
        }
        
        for(int i = 1; i < n-1; ++i)
        {
            travel[i] += travel[i-1];
        }

        int ret = 0;
        for(int i = 0; i < 3; ++i)
        {
            if(finalStop[i] > 0)
            {
                ret += travel[finalStop[i]-1];
            }
            ret += garbageCount[i];
        }      

        return ret;
    }
};