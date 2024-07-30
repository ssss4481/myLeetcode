#include <iostream>
#include <vector>
#include <cmath>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        vector<int> primes = {};
        int result = r-l+1;
        double l_root = sqrt(l);
        double r_root = sqrt(r);

        for(int i = 2; i <= r_root; ++i){
            if(isPrime(i, primes)){
                if(i >= l_root){
                   --result; 
                }
                primes.emplace_back(i);
            }
        }
        return result;        
    }
    
    bool isPrime(int n, vector<int>& primes){
        if(n == 2){
            return true;
        }

        double root = sqrt(n);

        for(auto& p: primes){
            if(p > root){
                break;
            }
            if(n % p == 0){
                return false;
            }
        }
        return true;        
    }
};