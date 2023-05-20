#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include "Matrix.hpp"


using namespace std;

void test(vector<int>& a)
{
    for(auto &val: a)
    {
        cout << val << " ";
    }
}


int main()
{
    bool a = true;
    int c = 3;
    c += a;
    cout << c;

    return 0;
}