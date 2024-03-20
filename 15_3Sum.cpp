#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());

        std::set<std::vector<int>> validCombination;

        for(int i = 0; i < nums.size()-2; ++i)
        {
            if(nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) 
            {
                continue;
            }

            int target = -nums[i];
            
            int j = i+1;
            int k = nums.size()-1;

            while(j < k)
            {
                int sum = nums[j]+nums[k];
                if(sum == target)
                {
                    validCombination.insert({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                }
                else if(sum < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
            }
        }

        std::vector<std::vector<int>> ret;

        for(auto& p: validCombination)
        {
            ret.push_back(p);
        }

        return ret;
    }
};




class Solution1//Too slow
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) 
    {
        std::unordered_map<std::string, std::vector<int>> hashMap;

        auto insert = [&hashMap](std::vector<int> value)
        {
            std::sort(value.begin(), value.end());
            std::string key = std::to_string(value[0]) + std::to_string(value[1]) + std::to_string(value[2]);
            if(hashMap.count(key) == 0)
            {
                hashMap[key] = value;
            }           
        };

        std::unordered_map<int, int> counts;
        std::vector<int> diffNums;
        for(auto&n :nums)
        {
            if(counts.count(n) == 0)
            {
                diffNums.push_back(n);
            }
            ++counts[n];
        }

        for(int i = 0; i < diffNums.size(); ++i)
        {
            int target = -diffNums[i];
            --counts[diffNums[i]];
            for(int j = i; j < diffNums.size(); ++j)
            {
                if(counts[diffNums[j]] > 0)
                {
                    --counts[diffNums[j]];
                    if(counts[target-diffNums[j]] > 0)
                    {
                        insert({diffNums[i], diffNums[j], target-diffNums[j]});
                    }
                    ++counts[diffNums[j]];
                }
            }
        }
        std::vector<std::vector<int>>ret;
        for(auto&p : hashMap)
        {
            ret.push_back(p.second);
        }
        return ret;
    }
};