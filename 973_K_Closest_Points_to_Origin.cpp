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

using namespace std;

struct Point{
    int index;
    int key;
    Point(){};
    Point(int i, const vector<int>& point){
        index = i;
        key = point[0]*point[0] + point[1]*point[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const Point& p1, const Point& p2){
            return p1.key > p2.key;
        };

        const int n = points.size();
        vector<Point> PQ(n);

        for(int i = 0; i < n; ++i){
            PQ[i] = Point(i, points[i]);
        }

        make_heap(PQ.begin(), PQ.end(), cmp);

        for(int i = 0; i < k; ++i){
            pop_heap(PQ.begin(), PQ.begin()+(n-i), cmp);
        }
        vector<vector<int>> res;
        auto it = PQ.rbegin();
        for(int i = 0; i < k; ++i){
            res.push_back(points[(*it).index]);
            ++it;
        }
        return res;
    }
};

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