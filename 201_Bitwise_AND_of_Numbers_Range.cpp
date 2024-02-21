#include <bitset>
#include <iostream>

class Solution 
{
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        const std::bitset<32> l = left;
        const std::bitset<32> r = right;
        std::bitset<32> ret = 0;

        bool needToStop = false;
        for(int i = 31; i >= 0; --i)
        {
            if(l[i] || r[i])
            {
                needToStop = true;
            }

            if(l[i] == r[i])
            {
                if(l[i] == 1)
                {
                    ret[i].flip();
                }
            }
            else if(needToStop)
            {
                break;
            }
        }

        return static_cast<int>(ret.to_ullong());    
    }
};


int main(int argc, char const *argv[])
{
    std::bitset<32> a = 1;
    std::bitset<32> b = 1;

    std::cout << a[0] && b[0] << '\n';

    return 0;
}
