#include <string>
#include <vector>
#include <algorithm>
#include <iostream>




class Solution 
{
public:
    std::string removeKdigits(std::string num, int k) 
    {
        if(num.length() == k)
        {
            return "0";
        }

        std::string ret = "";

        for(int i = 0; i < num.length(); ++i)
        {
            while(!ret.empty() && num[i] < ret.back() && k > 0)
            {
                --k;
                ret.pop_back();
            }
            ret.push_back(num[i]);
        }

        while(k > 0)
        {
            --k;
            ret.pop_back();
        }

        if(ret[0] == '0' && ret.length() > 1)
        {
            int i = 1;
            while(ret[i] == '0')
            {
                ++i;
            }
            ret = ret.substr(i);
        }

        if(ret == "")
        {
            return "0";
        }

        return ret;

    }
};





class Solution1//MLE 
{
public:
    std::string removeKdigits(std::string num, int k) 
    {
        std::vector<std::string> dp (k+1, "");
        dp[0] = num[0];
        dp[1] = "";

        for(int i = 1; i < num.length(); ++i)
        {
            std::vector<std::string> next (k+1, "");
            next[0] = dp[0] + num[i];
            const int MaxJ = std::min(i+1, k);
            for(int j = 1; j <= MaxJ; ++j)
            {
                //std::cout << dp[j-1] << ' ' << dp[j]+num[i] << '\n';
                next[j] = std::min(dp[j-1], dp[j]+num[i]);
            }
            //std::cout << "-----\n";
            dp.swap(next);
        }

        std::string& ret = dp[k];

        if(ret.length() > 1 && ret[0] == '0')
        {
            int i = 1;
            while (ret[i] == '0')
            {
                ++i;
            }
            ret = ret.substr(i);
        }
        if(ret == "")
        {
            return "0";
        }
        return ret;
    }
};