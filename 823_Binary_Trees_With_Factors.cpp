#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::unordered_map<int, int64_t> map;
    const int modulo = 1000000007;

    int numFactoredBinaryTrees(std::vector<int>& arr) 
    {
        std::sort(arr.begin(), arr.end());        
        int64_t res = 0;

        for(int& num: arr)
        {
            this->map[num] = 0;
        }

        for(int i = 0; i < arr.size(); ++i)
        {
            res += recursiveDP(arr, arr[i]);
            res %= this->modulo;
        }

        return int(res);
    }

    int64_t recursiveDP(const std::vector<int>& arr, const int& value)
    {
        if(this->map[value] != 0)
        {
            return this->map[value];
        }
        this->map[value] = 1;
        const double lim = std::sqrt(value);
        for(int i = 0; arr[i] <= lim; ++i)
        {
            if(value % arr[i] == 0 && this->map.count(value/arr[i]) != 0)
            {
                int64_t l = recursiveDP(arr, arr[i]);
                int64_t r = recursiveDP(arr, value/arr[i]);
                if(arr[i] == value/arr[i])
                {
                    this->map[value] += l*r;
                }
                else
                {
                    this->map[value] += 2*l*r;
                }
                this->map[value] %= this->modulo;
            }
        }
        return this->map[value];
    }
};