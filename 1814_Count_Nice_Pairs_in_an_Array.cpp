#include <vector>
#include <string>
#include <unordered_map>

class Solution 
{
public:
    int countNicePairs(std::vector<int>& nums) 
    {
        const int n = nums.size();
        std::unordered_map<int, long long int> deltaCount;

        auto rev = [](const int& num)
        {
            std::string s = std::to_string(num);
            std::reverse(s.begin(), s.end());
            return std::stoi(s);
        };

        for(const auto& num: nums)
        {
            ++deltaCount[std::abs(num - rev(num))];
        }

        long long int pairCount = 0;

        for(const auto& p : deltaCount)
        {
            pairCount += (p.second * (p.second-1) / 2ll) % 1000000007;
            pairCount %= 1000000007;
        }

        return int(pairCount);
    }
};