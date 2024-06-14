#include <vector>
#include <algorithm>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        const int n = students.size();

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int result = 0;
        for(int i = 0; i < n; ++i){
            result += abs(students[i]-seats[i]);
        }
        return result;
    }
};