#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        vector< vector<char> > rows(numRows);
        for(int i = 0; i < s.length();)
        {
            int j = 0;
            for(; j < numRows && i < s.length(); ++j)
            {
                rows[j].push_back(s[i]);
                ++i;
            }
            j -= 2;
            for(; j > 0 && i < s.length(); --j)
            {
                rows[j].push_back(s[i]);
                ++i;
            }
        }

        string ret = "";
        for(vector<char>& row : rows)
        {
            string subStr(row.begin(), row.end());
            //cout << "|" << subStr << "|\n";
            ret += subStr;
        }
        return ret;
    }
};


int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;
    Solution sol = Solution();
    cout << sol.convert(s, numRows) << "\n";



    return 0;
}