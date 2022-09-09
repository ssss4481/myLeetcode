#include <iostream>
#include <vector>

using namespace std;


void printVector(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}


void backtrackingChar(const int &n, const int &k, const int& current_idx, char num, char arr[], vector<int> &ret)
{
    if(current_idx > 0 && (num > '9' || num < '0'))
        return;
    arr[current_idx] = num;
    if(current_idx == n-1)
    {
        ret.push_back(atoi(arr));
        return;
    }
    else
    {
        backtrackingChar(n, k, current_idx+1, num-k, arr, ret);
        backtrackingChar(n, k, current_idx+1, num+k, arr, ret);
    }
}


void backtrackingInt(const int &n, const int &k, const int& current_idx, int num, int digit, vector<int> &ret)
{
    if(current_idx > 0 && (digit > 9 || digit < 0))
        return;
    if(current_idx == n-1)
    {
        ret.push_back(num*10 + digit);
        return;
    }
    else
    {
        num = num*10 + digit;
        backtrackingInt(n, k, current_idx+1, num, digit-k, ret);
        if(k > 0)
            backtrackingInt(n, k, current_idx+1, num, digit+k, ret);
    }
}



vector<int> numsSameConsecDiff(int n, int k)
{
    vector<int> ret;
    for(int i = 1; i <= 9; ++i)
    {
        backtrackingInt(n, k, 0, 0, i, ret);
    }
    return ret;
}

int main()
{
    vector<int> output = numsSameConsecDiff(2, 1);
    printVector(output);
    return 0;
}


