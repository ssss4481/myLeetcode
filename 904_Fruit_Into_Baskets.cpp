#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        int subType = fruits[0];
        int subsequence = 1;
        int currentMaxTotal = 1;
        int globalMaxTotal = 1;
        int type1 = fruits[0];
        int type2 = fruits[0];

        for(int i = 1; i < fruits.size(); ++i)
        {
            if(type1 == type2)
            {
                if(type1 == fruits[i])
                {
                    ++subsequence;
                    ++currentMaxTotal;
                }
                else
                {
                    type2 = fruits[i];
                    subType = fruits[i];
                    subsequence = 1;
                    ++currentMaxTotal;
                }
            }
            else
            {
                if(fruits[i] == type1 || fruits[i] == type2)
                {
                    ++currentMaxTotal;
                    if(subType == fruits[i])
                    {
                        ++subsequence;
                    }
                    else
                    {
                        subType = fruits[i];
                        subsequence = 1;
                    }
                }
                else
                {
                    if(currentMaxTotal > globalMaxTotal)
                        globalMaxTotal = currentMaxTotal;
                    currentMaxTotal = subsequence + 1;
                    subsequence = 1;
                    type1 = subType;
                    type2 = fruits[i];
                    subType = fruits[i];
                }
            }
        }
        if(currentMaxTotal > globalMaxTotal)
            globalMaxTotal = currentMaxTotal;

        return globalMaxTotal;
    }
};


class Solution2
{
public:
    int totalFruit(vector<int>& fruits)
    {
        int subType = fruits[0];
        int subsequence = 1;
        int currentMaxTotal = 1;
        int globalMaxTotal = 1;
        set<int> twoType ({fruits[0]});

        for(int i = 1; i < fruits.size(); ++i)
        {
            if(twoType.size() < 2)
            {
                if(twoType.count(fruits[i]) == 1)
                {
                    ++subsequence;
                    ++currentMaxTotal;
                }
                else
                {
                    twoType.insert(fruits[i]);
                    subType = fruits[i] ;
                    subsequence = 1;
                    ++currentMaxTotal;
                }
            }
            else
            {
                if(twoType.count(fruits[i]) == 1)
                {
                    ++currentMaxTotal;
                    if(subType == fruits[i])
                    {
                        ++subsequence;
                    }
                    else
                    {
                        subType = fruits[i];
                        subsequence = 1;
                    }
                }
                else
                {
                    if(currentMaxTotal > globalMaxTotal)
                        globalMaxTotal = currentMaxTotal;
                    currentMaxTotal = subsequence + 1;
                    subsequence = 1;
                    twoType = set<int>({subType, fruits[i]});
                    subType = fruits[i];
                }
            }
        }
        if(currentMaxTotal > globalMaxTotal)
            globalMaxTotal = currentMaxTotal;

        return globalMaxTotal;
    }
};


int main(int argc, char const *argv[])
{
    //test code for set operation.
    set<int> A ({1, 2});
    for(set<int>::iterator i = A.begin(); i != A.end(); ++i)
    {
        cout << *i << "\n";
    }
    A = set<int> ({8, 9});
    for(set<int>::iterator i = A.begin(); i != A.end(); ++i)
    {
        cout << *i << "\n";
    }
    return 0;
}
