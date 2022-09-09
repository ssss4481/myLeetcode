#include <iostream>

bool isPowerOfThree(int n)
{
    if(n <= 0) return false;
    if(n == 1) return true;
    long long int b = 3;
    while(b <= n)
    {
        if(b == n)
        {
            return true;
        }
        b = (b << 1) + b;
    }
    return false;
}

int main()
{
    for(int i = 0; i <= 27; ++i)
    {
        std::cout << i << " " << isPowerOfThree(i) << "\n";
    }

    return 0;
}