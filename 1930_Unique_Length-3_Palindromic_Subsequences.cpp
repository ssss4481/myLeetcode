#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

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
    int countPalindromicSubsequence(std::string s) 
    {       
        int first[26];
        int last[26];
        memset(first, -1, sizeof(first));
        memset(last, -1, sizeof(last));

        for(int i = 0; i < s.length(); ++i)
        {
            int c = int(s[i]-'a');
            if(first[c] == -1)
            {
                first[c] = i;
            }
            else
            {
                last[c] = i;
            }
        }

        int count = 0;

        for(char c = 0; c < 26; ++c)
        {
            if(last[c] != -1)
            {
                bool found[26]{false};
                int tmp = 0;
                for(int i = first[c]+1; i < last[c] && tmp < 26; ++i)
                {
                    if(!found[s[i]-'a'])
                    {
                        ++tmp;
                        found[s[i]-'a'] = true;
                    }                    
                }               
                count += tmp;
            }
        }

        return count;
    }
};


class SolutionF
{
public:
    int countPalindromicSubsequence(std::string s) 
    {       
        std::vector<std::pair<int, int>> leftAndRight(26, {-1, -1});
        for(int i = 0; i < s.length(); ++i)
        {
            auto& p = leftAndRight[int(s[i]-'a')];
            if(p.first == -1)
            {
                p.first = i;
            }
            else
            {
                p.second = i;
            }
        }

        int count = 0;

        for(char c = 0; c < 26; ++c)
        {
            auto& p = leftAndRight[c];
            if(p.second != -1)
            {
                std::vector<bool> cTable(26, false);
                for(int i = p.first+1; i < p.second; ++i)
                {
                    if(!cTable[s[i]-'a'])
                    {
                        ++count;
                        cTable[s[i]-'a'] = true;
                    }                    
                }               
            }
        }

        return count;
    }
};



class Solution2//too slow
{
public:
    int countPalindromicSubsequence(std::string s) 
    {       
        std::unordered_set<std::string> validPalindromic;
        std::unordered_set<char> leftSet;
        std::vector<int> rightTable(26, 0);
        auto charToIdx = [](char& c)
        {
            return c - 'a';
        };
        
        leftSet.insert(s[0]);
        
        for(int i = 1; i < s.length(); ++i)
        {
            ++rightTable[charToIdx(s[i])];
        }

        for(int mid = 1; mid < s.length()-1; ++mid)
        {
            --rightTable[charToIdx(s[mid])];
            for(int c = 0; c < 26; ++c)
            {
                if(rightTable[c] > 0 && leftSet.count('a' + c) == 1)
                {
                    char str[4];
                    str[0] = 'a'+c;
                    str[1] = s[mid];
                    str[2] = 'a'+c;
                    str[3] = '\0';
                    validPalindromic.insert(std::string(str));
                }
            }
            leftSet.insert(s[mid]);
        }     

        for(const auto& s: validPalindromic)
        {
            std::cout << s << '\n';
        }
        
        return int(validPalindromic.size());        
    }
};









class Solution3//TLE 
{
public:
    int countPalindromicSubsequence(std::string s) 
    {
        std::unordered_set<char> left;
        std::unordered_set<std::string> validPalindromic;

        left.insert(s[0]);
        for(int mid = 1; mid < s.length()-1; ++mid)
        {
            for(int right = mid+1; right < s.length(); ++right)
            {
                if(left.count(s[right]) == 1)
                {                    
                    char validStr[4];
                    validStr[0] = s[right];
                    validStr[1] = s[mid];
                    validStr[2] = s[right];
                    validStr[3] = '\0';
                    validPalindromic.insert(std::string(validStr));
                }
            }
            left.insert(s[mid]);
        }
        
        return int(validPalindromic.size());        
    }
};