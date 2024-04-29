#include <vector>
#include <deque>
#include <queue>
#include <iostream>
typedef struct myPair{
    int num;
    int index;
    myPair(){}
    myPair(int n, int i){
        num = n;
        index = i;
    }
}myPair;

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        
        int listsize = 0;
        for(auto& num : nums){
            listsize += num.size();
        }
        std::vector<myPair> list(listsize);
        int i = 0;
        int b = 0;
        for(auto& num: nums){
            for(auto& n: num){
                list[i] = myPair(n, b);
                ++i;
            }
            ++b;
        }
        auto cmp = [](const myPair& p1, const myPair& p2){
            return p1.num < p2.num;
        };
        std::sort(list.begin(), list.end(), cmp);

        int count[nums.size()];
        memset(count, 0, sizeof(count));
        int excluded_count = nums.size();

        std::vector<int> ret = {};

        int lo = 0;
        for(int i = 0; i < listsize; ++i){
            if(++count[list[i].index] == 1){
                --excluded_count;
            }
            if(excluded_count == 0){
                while(--count[list[lo++].index] != 0);
                std::vector<int> new_interval = {list[lo-1].num, list[i].num};
                if(ret.empty() || better_interval(ret, new_interval)){
                    ret.swap(new_interval);
                }
                ++excluded_count;
            }
        }
        return ret;
    }

    bool better_interval(std::vector<int>& src, std::vector<int>& dst){
        int& a = dst[0];
        int& b = dst[1];
        int& c = src[0];
        int& d = src[1];
        return (b-a < d-c) || ((b-a == d-c) && (a < c));
    }    
};