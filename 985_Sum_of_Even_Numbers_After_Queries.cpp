#include <vector>

using namespace std;


class Solution {
public:

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) 
    {
        vector<int> ret;
        int cur = 0;
        for(int &num : nums)
        {
            cur += (num % 2 == 0 ? num : 0);
        }

        for(auto &Q: queries)
        {
            if(Q[0] % 2 == 0 && nums[Q[1]] % 2 == 0)
            {                
                cur += Q[0];
            }
            else if (Q[0] % 2 != 0 && nums[Q[1]] % 2 == 0)
            {
                cur -= nums[Q[1]];
            }
            else if(Q[0] % 2 != 0 && nums[Q[1]] % 2 != 0)
            {
                cur += (Q[0] + nums[Q[1]]);
            }
            nums[Q[1]] += Q[0];
            ret.push_back(cur);
        }
        return ret;
    }
};

int main()
{
    return 0;
}