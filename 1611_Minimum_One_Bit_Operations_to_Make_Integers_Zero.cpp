#include <bitset>
#include <iostream>

class Solution 
{
public:
    int minimumOneBitOperations(int n) 
    {
        int ret = 0;
        std::bitset<32> p {static_cast<unsigned long long>(n)};
        while(p != 0)
        {
            

        }



        return ret;        
    }
};


int main(int argc, char const *argv[])
{
    std::bitset<32> p{0};
    std::cout << (p == 0) << '\n';



    return 0;
}
