#include <iostream>
#include <vector>



class MountainArray 
{
    private:
        std::vector<int> arr;
    public:
        MountainArray(std::vector<int> arr)
        {
            this->arr = std::move(arr);
        }
        int get(int index)
        {
            return this->arr[index];
        }
        int length()
        {
            return this->arr.size();
        }
};

const int fast_io = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}(); 

class Solution 
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        if(target < mountainArr.get(0) && target < mountainArr.get(mountainArr.length()-1))
        {
            return -1;
        }
        int top = this->findTop(0, mountainArr.length()-1, mountainArr);
        int topVal = mountainArr.get(top);
        if(topVal == target)
        {
            return top;
        }
        else if(topVal < target)
        {
            return -1;
        }

        int left = this->binarySearch(0, top-1, target, mountainArr);
        if(left != -1)
        {
            return left;
        }
        int right = this->binarySearch(top+1, mountainArr.length()-1, target, mountainArr);
        return right;
    }

    int findTop(int lo, int hi, MountainArray &mountainArr)
    {
        if(hi - lo == 1)
        {
            return mountainArr.get(hi) > mountainArr.get(lo) ? hi : lo;
        }
        int mid = (lo+hi)/2;
        if(mountainArr.get(mid) < mountainArr.get(mid-1))
        {
            return findTop(0, mid-1, mountainArr);
        }
        else
        {
            return findTop(mid, hi, mountainArr);
        }
    }

    int binarySearch(int lo, int hi, int target, MountainArray &mountainArr)
    {
        int mid;
        if(hi - lo <= 2)
        {
            mid = lo+1;
            if(mountainArr.get(hi) == target)
            {
                return hi;
            }
            else if(mountainArr.get(lo) == target)
            {
                return lo;
            }
            else if(mid < hi && mountainArr.get(mid) == target)
            {
                return mid;
            }
            else
            {
                return -1;
            }
        }
        mid = (lo+hi)/2;
        int val = mountainArr.get(mid);
        if(val == target)
        {
            return mid;
        }
        else if(val > target)
        {
            return binarySearch(lo, mid-1, target, mountainArr);
        }
        else
        {
            return binarySearch(mid+1, hi, target, mountainArr);
        }
    }

};


int main(int argc, char const *argv[])
{
    auto t1 = MountainArray({1,2,3,4,5,3,1});
    auto t2 = MountainArray({0,1,2,4,2,1});
    auto t3 = MountainArray({0, 5, 3, 1});

    std::cout << Solution().findTop(0, t3.length()-1, t3) << "\n";
    return 0;


    std::cout << Solution().findTop(0, t1.length()-1, t1) << "\n";
    std::cout << Solution().findTop(0, t2.length()-1, t2) << "\n";
    std::cout << Solution().findInMountainArray(3, t1) << '\n';
    std::cout << Solution().findInMountainArray(3, t2) << '\n';
    return 0;
}
