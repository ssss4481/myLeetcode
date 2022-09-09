#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

#include "Matrix.hpp"


using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        int maxAttack = 0;
        for(const auto &c : properties)
        {
            int attack = c[0];
            if (attack > maxAttack)
                maxAttack = c[0];
        }
        vector<int> maxDefense (maxAttack+2, 0);
        for(const auto &c : properties)
        {
            int attack = c[0];
            int defence = c[1];
            if(defence > maxDefense[attack])
                maxDefense[attack] = defence;
        }

        for(int i = maxAttack; i >= 1; --i)
        {
            maxDefense[i] = max(maxDefense[i], maxDefense[i+1]);
        }

        int counter = 0;

        for(const auto &c : properties)
        {
            int attack = c[0];
            int defence = c[1];
            if(defence < maxDefense[attack+1])
                ++counter;
        }
        return counter;
    }
};




int main()
{
    vector<vector<int>> test {{7,9},{10,7},{6,9},{10,4},{7,5},{7,10}};
    Solution obj;
    cout << obj.numberOfWeakCharacters(test) << "\n";


    return 0;
}