#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        unordered_map<int, int> order;
        for(int i = 0; i < arr2.size(); ++i){
            order[arr2[i]] = i;
        }

        auto cmp = [&](int x, int y){
            if(order.count(x) == 1 && order.count(y) == 1){
                return order[x] < order[y];
            }
            if(order.count(x) == 1){
                return true;
            }
            if(order.count(y) == 1){
                return false;
            }
            return x < y;
        };

        sort(arr1.begin(), arr1.end(), cmp);

        return arr1;
    }
};