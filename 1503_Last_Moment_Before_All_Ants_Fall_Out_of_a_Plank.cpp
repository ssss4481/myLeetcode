#include <vector>
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
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) 
    {
        int ans = 0;
        for(int& ant: left)
        {
            ans = std::max(ans, ant);
        }
        for(int& ant: right)
        {
            ans = std::max(ans, n-ant);
        }
        return ans;        
    }
};




struct antInfo
{
  int toLeft;
  int toRight;

  antInfo()
  {
    this->toLeft = 0;
    this->toRight = 0;
  }
};


class Solution //TLE
{
public:
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) 
    {
        if(n == 1)
        {
            return left.size()==0 && right.size() == 0 ? 0 : 1;        
        }

        int count = left.size() + right.size();
        int time = 0;
        std::vector<antInfo> currentPlank(n+1, antInfo());
        std::vector<antInfo> nextPlank(n+1, antInfo());

        for(int& ant: left)
        {
            ++currentPlank[ant].toLeft;
        }

        for(int& ant: right)
        {
            ++currentPlank[ant].toRight;
        }       

        auto leftEdgeUpdate = [&]()
        {
            if(currentPlank[0].toRight == 0)
            {
                count -= currentPlank[0].toLeft;
            }
            else if(currentPlank[0].toLeft == 0)
            {
                nextPlank[1].toRight += currentPlank[0].toRight;
            }
            else
            {
                count -= currentPlank[0].toRight;
                nextPlank[1].toRight += currentPlank[0].toLeft;
            }
        };

        auto rightEdgeUpdate = [&]()
        {
            if(currentPlank[n].toLeft == 0)
            {
                count -= currentPlank[n].toRight;
            }
            else if(currentPlank[n].toRight == 0)
            {
                nextPlank[n-1].toLeft += currentPlank[n].toLeft;
            }
            else
            {
                count -= currentPlank[0].toRight;
                nextPlank[n-1].toLeft += currentPlank[n].toRight;
            }
        };

        auto normalUpdate = [&](int& i)
        {

            if(currentPlank[i].toRight == 0)
            {
                nextPlank[i-1].toLeft += currentPlank[i].toLeft;
            }
            else if(currentPlank[i].toLeft == 0)
            {
                nextPlank[i+1].toRight += currentPlank[i].toRight;
            }
            else
            {
                nextPlank[i-1].toLeft += currentPlank[i].toRight;
                nextPlank[i+1].toRight += currentPlank[i].toLeft;
            }
        };

        while(count > 0)
        {
            ++time;
            leftEdgeUpdate();
            rightEdgeUpdate();
            for(int i = 1; i < n; ++i)
            {
                normalUpdate(i);
            }
            currentPlank.swap(nextPlank);
            std::fill(nextPlank.begin(), nextPlank.end(), antInfo());
        }

        return time-1;        
    }
};