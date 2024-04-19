#include <vector>
#include <cmath>
#include <unordered_set>


class Solution {
public:
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};
    std::unordered_set<int> primeSet {2, 3, 5, 7, 11, 13, 17, 19};

    bool isPrime (int n){
        if(primeSet.count(n) == 1){
            return true;
        }
        if(n == 1 || n % 2 == 0){
            return false;
        }        

        int sqrtValue = static_cast<int>(sqrt(n));
        if(primes.back() > sqrtValue){
            for(int i = primes.back()+1; i <= sqrtValue; ++i){
                if(isPrime(i)){
                    primes.push_back(i);
                    primeSet.insert(i);
                }
            }
        }

        for(auto& p : primes){
            if(p > sqrtValue){
                break;
            }
            if(n % p == 0){
                return false;
            }
        }
        return true;
    }


    int maximumPrimeDifference(std::vector<int>& nums) {
        int lo = -1; 
        int hi = -1;

        for(int i = 0; i < nums.size(); ++i){
            if(isPrime(nums[i])){
                if(lo == -1){
                    lo = i;
                }
                hi = i;
            }
        }

        return hi-lo;
    }
};