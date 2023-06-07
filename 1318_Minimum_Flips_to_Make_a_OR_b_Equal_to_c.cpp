#include <iostream>
class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        int cmp = 1;
        int count = 0;
        for(int i = 0; i < 31; ++i)
        {
            if(c & cmp)
            {
                if(!((a | b) & cmp))                
                    ++count;                  
            }
            else
            {
                if(a & cmp)
                    ++count;
                   
                if(b & cmp)
                    ++count;
            }
            cmp = cmp << 1;            
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    //std::cout << sol.minFlips(2, 6, 5);
    std::cout << sol.minFlips(4, 2, 7);

    // std::cout << (5&1) << "\n";
    // std::cout << (5&2) << "\n";
    // std::cout << (5&4) << "\n";

    return 0;
}
