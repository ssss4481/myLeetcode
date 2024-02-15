#include <unordered_map>
#include <vector>
#include <string>

class Solution 
{
public:
    bool isIsomorphic(std::string s, std::string t) 
    {
        std::vector<int> StoT(256, -1);
        std::vector<int> TtoS(256, -1);
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(StoT[s[i]] != -1 && StoT[s[i]] != t[i])
            {
                return false;
            }
            if(TtoS[t[i]] != -1 && TtoS[t[i]] != s[i])
            {
                return false;
            }            
            StoT[s[i]] = t[i];
            TtoS[t[i]] = s[i];
        }       

        return true;        
    }
};

class Solution1
{
public:
    bool isIsomorphic(std::string s, std::string t) 
    {
        std::unordered_map<char, char> StoT;
        std::unordered_map<char, char> TtoS;
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(StoT.count(s[i]) != 0 && StoT[s[i]] != t[i])
            {
                return false;
            }
            if(TtoS.count(t[i]) != 0 && TtoS[t[i]] != s[i])
            {
                return false;
            }            
            StoT[s[i]] = t[i];
            TtoS[t[i]] = s[i];
        }       

        return true;        
    }
};