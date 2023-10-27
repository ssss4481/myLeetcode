#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL); 

    return 0;
}();

class Solution 
{
public:
    std::string longestPalindrome(std::string s) 
    {
        
    }
};



int main(int argc, char const *argv[])
{    
    const int n = 4;
    for(int delta = 1; delta < n; ++delta)
    {
        for(int i = 0; i + delta < n; ++i)
        {
            std::cout << i << ' ' << i+delta << '\n';
        }
        std::cout << "---\n";
    }    
    return 0;
}
