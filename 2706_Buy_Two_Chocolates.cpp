#include <vector>
#include <iostream>
const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution 
{
public:
    int buyChoco(std::vector<int>& prices, int money) 
    {
        long long int choice1 = INT_MAX;
        long long int choice2 = INT_MAX;
        for(auto& price: prices)
        {
            if(price <= choice1)
            {
                choice2 = choice1;
                choice1 = price;
            }
            else if(price < choice2)
            {
                choice2 = price;
            }
        }

        if(choice1 + choice2 <= money)
        {
            return money - choice1 - choice2;
        }
        return money;        
    }
};