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
    string a = "abc";
    if(a[0] == 'a')
    {
        cout << "here\n";
    }

    return 0;
}