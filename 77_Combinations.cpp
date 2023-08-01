#include <vector>

using namespace std;

class Solution 
{
private:
    vector<vector<int>> ret;
    int n;
    int k;

public:
    void backTracking(int i, vector<int>& combination)
    {
        if(n - i + 1 < k - combination.size())
        {
            return;       
        }

        combination.push_back(i);
        if(combination.size() == k)
        {
            this->ret.push_back(combination);
        }
        else
        {
            for(int j = i+1; j <= this->n; ++j)
            {
                backTracking(j, combination);
            }
        }        
        combination.pop_back();    
        return;
    }


    vector<vector<int>> combine(int n, int k) 
    {
        this->n = n;
        this->k = k;
        vector<int> combination;
        for(int i = 1; i <= n; ++i)
        {
            this->backTracking(i, combination);
        }
        return this->ret;        
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
