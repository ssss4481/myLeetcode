#include <vector>
#include <queue>
using namespace std;

struct Fraction{
    vector<int> ans;
    double value;
    Fraction(){}
    Fraction(vector<int>& arr, int i, int j){
        ans = {arr[i], arr[j]};
        value = static_cast<double>(arr[i])/arr[j];
    }
    bool operator()(Fraction& a, Fraction& b){
        return a.value > b.value;
    }
};


class Solution {
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

        return PQ.top().ans;
    }
};