#include <vector>
#include <queue>
#include <algorithm>
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
    int getWinner(std::vector<int>& arr, int k) 
    {
        const int n = arr.size();

        if(k >= n)
        {
            return *std::max_element(arr.begin(), arr.end());
        }

        std::queue<int> q(std::deque<int>(arr.begin()+1, arr.end()));
        int winner = arr[0];
        int winCount = 0;
        while(winCount < k)
        {
            if(winner > q.front())
            {
                ++winCount;
                q.push(q.front());
            }
            else
            {
                q.push(winner);
                winner = q.front();
                winCount = 1;            
            }
            q.pop();
        }
        return winner;        
    }
};


class Solution2//TLE
{
public:
    int getWinner(std::vector<int>& arr, int k) 
    {
        const int n = arr.size();

        if(k >= n)
        {
            return *std::max_element(arr.begin(), arr.end());
        }

        int winner = arr[0];
        arr.erase(arr.begin());
        int winCount = 0;
        while(winCount < k)
        {
            if(winner > arr.front())
            {
                ++winCount;
                arr.push_back(arr.front());
            }
            else
            {
                arr.push_back(winner);
                winner = arr.front();
                winCount = 1;            
            }
            arr.erase(arr.begin());
        }
        return winner;        
    }
};