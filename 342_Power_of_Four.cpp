#include <iostream>

bool isPowerOfFour(int n)
{
    if(n <= 0)
        return false;

    if(n == 1)
        return true;

    int t = 1;
    while(t < 0x40000000)
    {
        t <<= 2;
        if(t == n)
        {
            return true;
        }

        if(t > n)
        {
            break;
        }

    }
    return false;
}

int main()
{
    std::cout << isPowerOfFour(1) << "\n";
    std::cout << isPowerOfFour(16) << "\n";
    std::cout << isPowerOfFour(15) << "\n";
    std::cout << isPowerOfFour(13) << "\n";
    std::cout << isPowerOfFour(2) << "\n";
    std::cout << isPowerOfFour(1) << "\n";
    std::cout << isPowerOfFour(1073741824) << "\n";
    return 0;
}