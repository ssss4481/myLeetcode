#include <iostream>
#include <algorithm>

using namespace std;

void test1(void)
{
    int i = 1;
    while(i <= 0x20000000)
    {
        cout << i <<"\n";
        i <<= 1;
    }

}



void test2(void)
{
    int i = 1;
    while(i < 0x20000000)
    {
        i <<= 1;
        cout << i <<"\n";
    }

}


bool reorderedPowerOf2(int n)
{
    if(n == 1)
    {
        return true;
    }
    string num = to_string(n);
    sort(num.begin(), num.end());
    int i = 1;
    while(i < 0x20000000)
    {
        cout << i << endl;
        string cmp = to_string(i);
        sort(cmp.begin(), cmp.end());
        if(num == cmp)
        {
            cout << i << "pow1\n";
            return true;
        }
        i <<= 1;
    }
    return false;
}


bool re(int n)
{
    if(n == 1)
    {
        return true;
    }
    string num = to_string(n);
    sort(num.begin(), num.end());
    int i = 1;
    while(i < 0x20000000)
    {
        i <<= 1;
        string cmp = to_string(i);
        sort(cmp.begin(), cmp.end());
        if(num == cmp)
        {
            cout << i << "pow1\n";
            return true;
        }

    }
    return false;
}


int main()
{
    test1();
    test2();

    return 0;
}