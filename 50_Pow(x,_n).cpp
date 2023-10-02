#include <iostream>
using namespace std;


class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    double myPow(double x, long long int n) 
    {      
        if(n < 0)
        {
            double res = Pow(x, -n);
            return 1 / res;
        }
        return this->Pow(x, n);   
    }

    double Pow(double x, long long int n)
    {       
        if(n == 0)
        {
            return 1;
        }
        if(n == 1)
        {
            return x;
        }
        if(n % 2)
        {
            return x * this->Pow(x*x, n/2);
        }
        return this->Pow(x*x, n/2);            
    }    
};


int main(int argc, char const *argv[])
{
    
    cout << 1/std::numeric_limits<double>::infinity() << '\n';
    return 0;
}
