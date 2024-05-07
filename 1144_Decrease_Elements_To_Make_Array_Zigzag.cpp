#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() <= 1){
            return 0;
        }
        int oddCase = 0;
        int evenCase = 0;
        
        evenCase += max(nums[0]-nums[1]+1, 0);
        for(int i = 2; i < nums.size(); i += 2){
            if(i+1 < nums.size()){
                evenCase += max(nums[i]-min(nums[i+1], nums[i-1])+1, 0);
            }else{
                evenCase += max(nums[i]-nums[i-1]+1, 0);
            }
        }

        for(int i = 1; i < nums.size(); i += 2){
            if(i+1 < nums.size()){
                oddCase += max(nums[i]-min(nums[i+1], nums[i-1])+1, 0);
            }else{
                oddCase += max(nums[i]-nums[i-1]+1, 0);
            }
        }        
        return min(oddCase, evenCase);
    }
};