#include <vector>
#include <algorithm>
using namespace std;


class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        const int n = citations.size();        
        sort(citations.begin(), citations.end());
        int paperCount = n;
        int h = 0;
        for(int i = 0; i < n; ++i)
        {
            h = max(h, min(citations[i], paperCount));
            if(paperCount < citations[i])
            {
                break;
            }
            --paperCount;
        }
        return h;
    }
};