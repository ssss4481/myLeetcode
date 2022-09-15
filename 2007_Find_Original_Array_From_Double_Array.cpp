#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution {
public:
    int table[100001];

    vector<int> findOriginalArray(vector<int>& changed) {        
        
        //ios_base::sync_with_stdio(false);
        //cin.tie(NULL), cout.tie(NULL);
        if(changed.size() & 1)
            return {};

        

        for(auto& num : changed)
        {
            ++table[num];
        }

        if(table[0] & 1)
            return {};
        
        vector<int> ret;

        for(int i = 100000; i > 0; --i)
        {
            if(table[i])
            {
                if(((i & 1) && table[i] > 0) || table[i] < 0 || (table[i/2] -= table[i]) < 0)
                    return {};
                for(int j = 0; j < table[i]; ++j)
                {
                    ret.push_back(i/2);                
                }                 

            }
                     
        }
        for(int j = 0; j < table[0]/2; ++j)
        {
            ret.push_back(0);
        }
        return ret;
    }
};



class Solution2 {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ret(changed.size()/2);
        vector<int> empty;

        if(changed.size() & 1)
            return empty;      

        sort(changed.begin(), changed.end());

        queue<int> q;
        int idx = 0;

        for(auto &num: changed)
        {
            if(q.empty() || q.front() != num)
            {
                q.push(num*2);
            }
            else
            {
                ret[idx] = q.front()/2;                
                q.pop();
                ++idx;
            }
        }

        if(q.empty())
            return ret;

        return empty;        
    }
};

int main()
{
    return 0;
}