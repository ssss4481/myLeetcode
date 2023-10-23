#include <iostream>

const int n = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    bool isPowerOfFour(int n)
    {
        if(n <= 0)
            return false;

        if(n == 1)
            return true;

        int t = 1;
        while(t < 0x40000000 && t < n)
        {
            t <<= 2;
            if(t == n)
            {
                return true;
            }          
        }
        return false;
    }

};

int main()
{
    std::cout << Solution().isPowerOfFour(1) << "\n";
    std::cout << Solution().isPowerOfFour(16) << "\n";
    std::cout << Solution().isPowerOfFour(15) << "\n";
    std::cout << Solution().isPowerOfFour(13) << "\n";
    std::cout << Solution().isPowerOfFour(2) << "\n";
    std::cout << Solution().isPowerOfFour(1) << "\n";
    std::cout << Solution().isPowerOfFour(1073741824) << "\n";
    return 0;
}