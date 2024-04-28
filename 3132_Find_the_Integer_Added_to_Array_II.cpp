#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
class Solution {
public:
    int minimumAddedInteger(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int best = INT_MAX;
        for(int i = 0; i < nums1.size(); ++i){
            for(int j=i+1; j < nums1.size(); ++j ){
                std::stack<int> st;
                int k = 0;
                int l = 0;
                bool valid = true;
                while(k < nums2.size()){
                    if(l == i || l == j){
                        ++l;
                        continue;;
                    }
                    if(st.empty()){
                        st.push(nums2[k++]-nums1[l++]);
                    }else{
                        if(nums2[k++]-nums1[l++] != st.top()){
                            valid = false;
                            break;
                        }
                    }
                }
                if(valid){
                    best = std::min(best, st.top());
                }
            }
        }
        return best;
    }
};