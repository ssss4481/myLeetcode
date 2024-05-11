#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int n = arr.size();
        double left = 0; 
        double right = 1.0;
        int numerator = 0;
        int denominator = 0;        

        while(left < right){
            double mid = (left+right)/2;
            double maxFraction = 0.0;
            int smaller_count = 0;

            for(int i = 1; i < n; ++i){
                for(int j = 0; j < i; ++j){
                    double value = static_cast<double>(arr[j])/arr[i];
                    if(value <= mid){
                        if(value > left){
                            ++smaller_count;
                            if(value > maxFraction){
                                maxFraction = value;
                                numerator = arr[j];
                                denominator = arr[i];
                            }
                        }
                    }else{
                        break;
                    }
                }
            }

            if(smaller_count == k){
                return {numerator, denominator};
            }

            if(smaller_count > k){
                right = mid;
            }else{
                left = mid;
                k -= smaller_count;
            }
        }


        return {};
    }
};












struct Fraction{
    int a;
    int b;
    double value;
    Fraction(){}
    Fraction(vector<int>& arr, int i, int j){
        a = arr[i];
        b = arr[j];
        value = static_cast<double>(arr[i])/arr[j];
    }
    bool operator()(Fraction& a, Fraction& b){
        return a.value > b.value;
    }
};


class Solution1 {//too slow
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<Fraction, vector<Fraction>, Fraction> PQ;

        for(int i = 0; i < arr.size(); ++i){
            for(int j = i+1; j < arr.size(); ++j){
                PQ.push(Fraction(arr, i, j));
            }
        }

        for(int i = 1; i <= k-1; ++i){
            PQ.pop();
        }

        return {PQ.top().a, PQ.top().b};
    }
};