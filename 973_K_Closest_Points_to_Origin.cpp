#include <vector>
#include <queue>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

typedef struct Data{
    int index;
    long long key;
    Data(){}
    Data(int _index, long long _key){
        index = _index;
        key = _key;
    }
}Data;

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        auto cmp = [](const Data& lhs, const Data& rhs)
        {
            return lhs.key > rhs.key;
        };
        std::priority_queue <Data, std::vector<Data>, decltype(cmp)> PQ(cmp);

        for(int i = 0; i < points.size(); ++i){
            auto data = Data(i, static_cast<long long>(points[i][0])*points[i][0] + static_cast<long long>(points[i][1])*points[i][1]);
            PQ.push(std::move(data));
        }

        std::vector<std::vector<int>> ret;

        for(int i = 1; i <= k; ++i){
            ret.push_back(points[PQ.top().index]);
            PQ.pop();
        }

        return ret;
    }
};