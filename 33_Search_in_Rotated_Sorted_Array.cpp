#include <algorithm>
#include <vector>
#include <iostream>

class Solution 
{
public:
    int search(std::vector<int>& nums, int target) 
    {   
        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            return -1;
        }

        std::vector<int>::iterator pLB;//pointer of lower bound.

        if(nums.back() > nums.front())
        {
            if(target > nums.back() || target < nums.front())
            {
                return -1;
            }

            pLB = std::lower_bound(nums.begin(), nums.end(), target);
            
            if(*pLB == target)
            {
                return static_cast<int>(pLB-nums.begin());
            }
            return -1;
        }

        int rotatePos = this->rotateStart(nums, 0, static_cast<int>(nums.size()-1));

        if(target > nums[rotatePos-1] || target < nums[rotatePos])
        {
            return -1;
        }
        
        if(target >= nums[0])
        {
            pLB = std::lower_bound(nums.begin(), nums.begin()+rotatePos, target);
        }
        else
        {
            pLB = std::lower_bound(nums.begin()+rotatePos, nums.end(), target);
        }

        if(pLB != nums.end() && *pLB == target)
        {
            return static_cast<int>(pLB-nums.begin());
        }        
        return -1;
    }

    int rotateStart(std::vector<int>& nums, int lo, int hi)
    {
        int mid = (lo+hi)/2;
        if(lo+1 == hi)
        {
            if(nums[lo] < nums[hi])
            {
                return lo;
            }
            return hi;
        }

        if(nums[mid] > nums[mid+1])
        {
            return mid+1;
        }

        if(nums[mid] > nums[0])
        {
            return rotateStart(nums, mid, hi);
        }
        else
        {
            return rotateStart(nums, lo, mid);
        }
    }
};



using namespace std;

class Solution2 
{
public:

    int search(vector<int>& nums, int target) 
    {
        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
            return -1;
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

        //cout << smallestIdx << "\n\n";

        if(smallestIdx != 0)
        {
            int firstSearch = binarySearchFilter(nums, 0, largestIdx, target);
            int secondSearch = binarySearchFilter(nums, smallestIdx, nums.size()-1, target);
            if(firstSearch != -1)
            {
                return firstSearch;
            }
            else if(secondSearch != -1)
            {
                return secondSearch;
            }
            return -1;
        }
        else
        {
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
        if(nums[mid] < nums[hi])
        {
            return findRotatedStart(nums, lo, mid);
        }
        else
        {
            return findRotatedStart(nums, mid, hi);
        }
    }

    int binarySearchFilter(const vector<int>& nums, int lo, int hi, const int& target)    
    {
        if(target < nums[lo] || target > nums[hi])
        {
            return -1;
        }
        return binarySearch(nums, lo, hi, target);    
    }           

    int binarySearch(const vector<int>& nums, int lo, int hi, const int& target)
    {
        int mid = (lo + hi)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        
        if(hi - lo <= 1)
        {
            if(nums[hi] == target)
            {
                return hi;
            }
            else if(nums[lo] == target)
            {
                return lo;
            }
            else
            {
                return -1;
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
    std::vector<int> a = {4,5,6,7,8,0,1,2,3};
    std::cout << Solution().rotateStart(a, 0, a.size()-1) << '\n';
    

    return 0;
}
