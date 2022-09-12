#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Matrix.hpp"

using namespace std;

void test(int a)
{
    if(a > 3) return;
    cout << a << "\n";
    ++a;
    cout << a << "\n";
    test(a);
}


int main()
{
    vector<int> temp {2, 4, 1, 8, 11, 7};

    sort(temp.begin(), temp.end());

    vectorMethod::printVector(temp);

    sort(temp.rbegin(), temp.rend());

    vectorMethod::printVector(temp);


    return 0;
}