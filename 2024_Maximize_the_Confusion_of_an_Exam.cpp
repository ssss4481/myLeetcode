#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int parse(const string& answerKey, const int& k, const char target)
    {
        const int n = answerKey.length();
        int ret = 1;
        int lo = 0;
        int hi = 0;
        int modification = answerKey[0] == target ? 0 : 1;
        
        while(hi < n)
        {  
            ++hi;                      
            if(hi == n)
            {
                break;
            }

            if(answerKey[hi] != target)
            {
                ++modification;            
            }

            if(modification <= k)
            {
                ret = max(ret, hi-lo+1);
            }

            while(modification > k)
            {
                if(answerKey[lo] != target)
                {
                    --modification;
                }
                ++lo;
            }
        }
        return ret;
    }

    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int T = parse(answerKey, k, 'T');
        int F = parse(answerKey, k, 'F');
        return max(T, F);        
    }
};




class WrongSolution 
{
public:
    int parse(string& answerKey, int& k, char target)
    {
        int modification = 0;
        int consecutiveCharWithKModification = 0;
        int currentConsecutiveCharWithoutModification = 0;
        int ret = 1;
        
        for(char& c: answerKey)
        {
            if(c == target)
            {
                ++consecutiveCharWithKModification;
                ++currentConsecutiveCharWithoutModification;
            }
            else
            {
                if(modification < k)
                {
                    ++modification;
                    ++consecutiveCharWithKModification;
                    currentConsecutiveCharWithoutModification = 0;
                }
                else
                {
                    ret = max(ret, consecutiveCharWithKModification);
                    modification = 1;
                    consecutiveCharWithKModification = currentConsecutiveCharWithoutModification+1;
                    currentConsecutiveCharWithoutModification = 0;
                }
            }
        }
        // cout << modification <<"---" << consecutiveCharWithKModification << "---" << target << '\n';
        // cout << consecutiveCharWithKModification+k-modification << ' ' << int(answerKey.length()) << '\n';        
        consecutiveCharWithKModification = min(consecutiveCharWithKModification+k-modification, int(answerKey.length()));
        ret = max(ret, consecutiveCharWithKModification);       

        return ret;
    }

    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        int T = parse(answerKey, k, 'T');
        int F = parse(answerKey, k, 'F');
        // cout << T << '\n';
        // cout << F << '\n';


        return max(T, F);        
    }
};