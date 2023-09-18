#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;//(index, score)

class Solution 
{
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)     
    {
        vector<int> ret;

        auto cmp = [](const pi& a, const pi& b)
        {
            if(a.second == b.second)
            {
                return a.first > b.first;
            }
            return a.second > b.second;
        };

        priority_queue<pi, vector<pi>, decltype(cmp)> PQ(cmp);

        for(int i = 0; i < mat.size(); ++i)
        {
            PQ.push(make_pair(i, accumulate(mat[i].begin(), mat[i].end(), 0)));
        }


        for(int i = 1; i <= k; ++i)
        {
            ret.push_back(PQ.top().first);
            PQ.pop();
        }

        return ret;        
    }
};



int main(int argc, char const *argv[])
{
    




    return 0;
}
