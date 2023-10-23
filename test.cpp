#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<vector<int>> a {{1},{2},{3}};
    auto& t = a[0];
    cout << t.size() << '\n';
    a[0][0]=2;
    cout << t.size() << '\n';
    return 0;
}
