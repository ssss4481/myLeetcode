#include <iostream>
#include <vector>
#include <string>


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

    char arr[3];
    arr[0] = '1';
    arr[1] = '3';
    arr[2] = '7';
    cout << atoi(arr);

    return 0;
}