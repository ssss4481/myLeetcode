#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    vector<int> testbool (10, 0);
    test(testbool);

    return 0;
}