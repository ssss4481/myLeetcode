#include <cstdlib>
#include <numeric>
#include <vector>

class Solution {
public:
    std::vector<double> CDF;

    Solution(std::vector<int>& w) {
        long long sum = std::accumulate(w.begin(), w.end(), 0LL);
        this->CDF = std::vector<double> (w.size(), 0);
        this->CDF[0] = static_cast<double>(w[0])/sum;

        for(int i = 1; i < w.size(); ++i){
            this->CDF[i] = static_cast<double>(w[i])/sum + this->CDF[i-1];
        }
    }
    
    int pickIndex() {
        double p = static_cast<double>(rand()%100)/100;
        auto it = std::upper_bound(this->CDF.begin(), this->CDF.end(), p);
        return static_cast<int> (it - this->CDF.begin());
    }
};

