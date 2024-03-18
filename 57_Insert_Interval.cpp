#include <iostream>
#include <vector>
#include <algorithm>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution
{
public:
    std::vector<std::vector<int>> insert(std::vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        auto overlapping = [](std::vector<int>& interval1, std::vector<int>& interval2)
        {
            return !(interval1[1] < interval2[0] || interval1[0] > interval2[1]);
        };

        int i = 0;
        std::vector<std::vector<int>> ret;

        while(i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            ret.push_back(intervals[i++]);
        }

        while (i < intervals.size())
        {
            if(overlapping(intervals[i], newInterval))
            {
                newInterval[0] = std::min(intervals[i][0], newInterval[0]);
                newInterval[1] = std::max(intervals[i][1], newInterval[1]);
                ++i;
            }
            else
            {
                break;
            }
        }

        ret.push_back(newInterval);

        while (i < intervals.size())
        {
            ret.push_back(intervals[i++]);
        }     
        return ret;
    }    
};

using namespace std;

class Solution2 
{
public:
    //If an overlap occurs, return the index.
    //Otherwise, return the index which should be the left element of it with negative value.
    //Special case will be handled in binarySearch.
    bool contain(const vector<int>& interval, const int& value)
    {
        return interval[0] <= value && value <= interval[1];
    }


    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        return intervals;
    }
};

class Solution 
{
public:
    //If an overlap occurs, return the index.
    //Otherwise, return the index which should be the left element of it with negative value.
    //Special case will be handled in binarySearch.
    bool contain(const vector<int>& interval, const int& value)
    {
        return interval[0] <= value && value <= interval[1];
    }

    int recursiveHelper(const vector<vector<int>>& intervals, const int& value, int lo, int hi)
    {
        int mid = (lo+hi)/2;
        if(hi - lo <= 1)
        {
            if(this->contain(intervals[lo], value))
                return lo+1;
            if(this->contain(intervals[hi], value))
                return hi+1;
            if(intervals[hi][1] < value)
                return -(hi+1);
            if(intervals[lo][1] < value)
                return -(lo+1);                
            
            return 0;//no left interval found in intervals.
        }

        if(this->contain(intervals[mid], value))
        {
            return mid+1;
        }
        else
        {
            if(intervals[mid][0] > value)
                return this->recursiveHelper(intervals, value, lo, mid);
            else
                return this->recursiveHelper(intervals, value, mid, hi);
        }         
    }

    void binarySearch(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int leftIdx = this->recursiveHelper(intervals, newInterval[0], 0, intervals.size()-1);
        int rightIdx = this->recursiveHelper(intervals, newInterval[1], 0, intervals.size()-1);               
        
        cout<< leftIdx << "\n" << rightIdx << "\n";   

        //both idx == 0 case is handled by insert function
        if(leftIdx == 0)
        {
            if(rightIdx > 0)//second number is included
            {
                intervals[rightIdx-1][0] = newInterval[0];
                intervals.erase(intervals.begin(), intervals.begin()+rightIdx-1);
            }
            else// rightIdx < 0
            {
                rightIdx = -rightIdx;
                intervals.erase(intervals.begin(), intervals.begin()+rightIdx);
                intervals.insert(intervals.begin(), std::move(newInterval));
            }
        }
        else if(leftIdx > 0 && rightIdx > 0)
        {
            if(leftIdx != rightIdx)
            {
                vector<int> newInstance = {intervals[leftIdx-1][0], intervals[rightIdx-1][1]};
                intervals.erase(intervals.begin()+leftIdx-1, intervals.begin()+rightIdx);
                intervals.insert(intervals.begin()+leftIdx-1, std::move(newInstance));              
            }
        }
        else if(leftIdx > 0 && rightIdx < 0)
        {
            rightIdx = -rightIdx;
            intervals[leftIdx-1][1] = newInterval[1];       
            intervals.erase(intervals.begin()+leftIdx, intervals.begin()+rightIdx);
        }
        else if(leftIdx < 0 && rightIdx > 0)
        {
            leftIdx = -leftIdx;
            intervals[rightIdx-1][0] = newInterval[0];
            intervals.erase(intervals.begin()+leftIdx, intervals.begin()+rightIdx-1);              
        }
        else
        {
            leftIdx = -leftIdx;
            rightIdx = -rightIdx;
            intervals.erase(intervals.begin()+leftIdx, intervals.begin()+rightIdx);              
            intervals.insert(intervals.begin()+leftIdx, std::move(newInterval));
        }
  
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        if(intervals.size() == 0)
            intervals.push_back(std::move(newInterval));
        else if(intervals[0][0] > newInterval[1])
            intervals.insert(intervals.begin(), std::move(newInterval));       
        else
            this->binarySearch(intervals, newInterval);
        return intervals;
    }
};

int main(int argc, char const *argv[])
{
    Solution testObj = Solution();
    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    //vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};//[[1,2],[3,5],[6,7],[8,10],[12,16]]
    int leftValue = 4;
    int rightValue = 8;
    cout << testObj.recursiveHelper(intervals, leftValue, 0, intervals.size()-1) << "----\n";
    cout << testObj.recursiveHelper(intervals, rightValue, 0, intervals.size()-1) << "----\n";    
    return 0;
}
