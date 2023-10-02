#include <string>
#include <iostream>
using namespace std;

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution//n
{
public:
    bool winnerOfGame(string colors)
    {
        int ACount = 0;
        int BCount = 0;
        bool modeA = (colors[0] == 'A' ? true : false);
        int seqCount = 1;

        for(int i = 0; i < colors.length(); ++i)
        {
            if((modeA && colors[i+1] == 'A') || (!modeA && colors[i+1] == 'B'))
            {
                ++seqCount;
            }
            else
            {
                if(seqCount > 2)
                {
                    if(modeA)
                    {
                        ACount += (seqCount-2);
                    }
                    else
                    {
                        BCount += (seqCount-2);
                    }
                }
                modeA = !modeA;
                seqCount = 1;
            }       
        }
        return ACount > BCount;       
    }
};

class Solution2//n
{
public:
    bool winnerOfGame(string colors)
    {
        int ACount = 0;
        int BCount = 0;
        bool modeA = (colors[0] == 'A' ? true : false);
        int seqCount = 1;

        for(int i = 1; i < colors.length(); ++i)
        {
            if(colors[i] == 'A')
            {
                if(modeA)
                {
                    ++seqCount;
                }
                else
                {
                    if(seqCount > 2)
                    {
                        BCount += (seqCount-2);
                    }
                    seqCount = 1;
                    modeA = true;
                }
            }
            else
            {
                if(!modeA)
                {
                    ++seqCount;
                }
                else
                {
                    if(seqCount > 2)
                    {
                        ACount += (seqCount-2);
                    }
                    seqCount = 1;
                    modeA = false;
                }
            }
        }

        if(seqCount > 2)
        {
            if(modeA)
            {
                ACount += (seqCount-2);
            }
            else
            {
                BCount += (seqCount-2);
            }
        }

        return ACount > BCount;       
    }
};

class Solution3//2n
{
public:
    bool winnerOfGame(string colors) 
    {
        auto countChar = [&](char c)
        {
            int count = 0;
            bool start = false;
            int seqCount = 0;
            for(int i = 0; i < colors.length(); ++i)
            {
                if(colors[i] == c)
                {
                    ++seqCount;                                        
                }
                else
                {
                    if(seqCount > 2)
                    {
                        count += (seqCount-2);
                    }
                    seqCount = 0;
                }
            }
            if(seqCount > 2)
            {
                count += (seqCount-2);
            }            
            return count;
        };
        return countChar('A') > countChar('B');        
    }
};