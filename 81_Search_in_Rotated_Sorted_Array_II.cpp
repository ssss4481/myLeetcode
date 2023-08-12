#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

class Solution 
{
public:

    bool search(vector<int>& nums, int target) 
    {
        while(nums.back() == nums.front() && nums.size() > 1)
        {
            nums.pop_back();
        }

        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                return true;
            }
            return false;
        }


        int smallestIdx;
        int largestIdx;
        


        if(nums.back() > nums.front())
        {
            smallestIdx = 0;            
            largestIdx = nums.size()-1;
        }
        else
        {
            smallestIdx = findRotatedStart(nums, 0, nums.size()-1);
            largestIdx = smallestIdx-1;
        }

        //cout << smallestIdx << " 5555\n\n";

        if(smallestIdx != 0)
        {
            //cout << "logic1\n";
            bool firstSearch = binarySearchFilter(nums, 0, largestIdx, target);
            if(firstSearch)
            {
                return true;
            }
            bool secondSearch = binarySearchFilter(nums, smallestIdx, nums.size()-1, target);            
            //cout << secondSearch << "---\n";
            return secondSearch;
        }
        else
        {
            //cout << "logic2\n";
            return binarySearchFilter(nums, 0, nums.size()-1, target);
        } 
    }

    int findRotatedStart(vector<int>& nums, int lo, int hi)
    {
        if(hi - lo == 1)
        {
            return hi;
        }
        int mid = (lo+hi)/2;
        if(nums[mid] < nums[mid-1])
        {
            return mid;
        }
        if(nums[mid] <= nums[hi])
        {
            return findRotatedStart(nums, lo, mid);
        }
        else
        {
            return findRotatedStart(nums, mid, hi);
        }
    }

    bool binarySearchFilter(const vector<int>& nums, int lo, int hi, const int& target)    
    {
        //cout << target << "\t" << nums[lo] << "\t" << nums[hi] << "\n";
        //cout << lo << ' ' << hi << ' ' << target << "---here---\n";
        if(target < nums[lo] || target > nums[hi])
        {
            return false;
        }
        return binarySearch(nums, lo, hi, target);    
    }           

    bool binarySearch(const vector<int>& nums, int lo, int hi, const int& target)
    {
        int mid = (lo + hi)/2;
        if(nums[mid] == target)
        {
            return true;
        }
        
        if(hi - lo <= 1)
        {
            if(nums[hi] == target)
            {
                return true;
            }
            else if(nums[lo] == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if(nums[mid] < target)
        {
            return binarySearch(nums, mid, hi, target);
        }
        else
        {
            return binarySearch(nums, lo, mid, target);
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> test = {2,5,6,0,0,1,2};
    vector<int> test2 = {1, 0, 1, 1, 1};
    vector<int> test3 = {3, 5, 1};
    
    cout << Solution().search(test3, 1);





    //cout << Solution().search(test, 0) << '\n';


    
    return 0;
}
