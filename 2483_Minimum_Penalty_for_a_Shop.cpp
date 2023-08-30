#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution 
{
public:
    int bestClosingTime(string customers)     
    {
        const int n = customers.length();
        int currentPenalty = 0;
        int minPenalty = 0;
        int bestCloseTime = 0;
        
        for(int i = 0; i < n; ++i)
        {
            if(customers[i] == 'Y')
            {
                --currentPenalty;
            }
            else
            {
                ++currentPenalty;
            }

            if(currentPenalty < minPenalty)
            {                
                bestCloseTime = i+1;
                minPenalty = currentPenalty;
            }


        }

        return bestCloseTime;
    }
};



class Solution2 
{
public:
    int bestClosingTime(string customers) 
    {
        const int32_t n = customers.length();
        vector<int32_t> Y_accu(n, 0);
        Y_accu[n-1] = customers[n-1] == 'Y' ? 1 : 0;

        for(int32_t i = n-2; i >= 0; --i)
        {
            Y_accu[i] = customers[i] == 'Y' ? Y_accu[i+1]+1 : Y_accu[i+1];
        }

        int32_t best_close_time = n;
        int32_t lowest_penalty = n - Y_accu[0];
        int32_t current_open_penalty = 0;


        for(int32_t i = 0; i < n; ++i)
        {
            int32_t close_penalty = Y_accu[i] + current_open_penalty;
            if(close_penalty < lowest_penalty)
            {
                lowest_penalty = close_penalty;
                best_close_time = i;
            }
            else if(close_penalty == lowest_penalty && i < best_close_time)
            {
                best_close_time = i;
            }

            if(customers[i] == 'N')
            {
                ++current_open_penalty;
            }

        }

        return best_close_time;       
    }
};
