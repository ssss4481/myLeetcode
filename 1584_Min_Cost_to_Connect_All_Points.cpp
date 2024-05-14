#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class Solution {//Prim
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        vector<char> visited(n, 0);
        vector<int> key(n, INT_MAX);
        key[0] = 0;
        int cost = 0;

        for(int i = 0; i < n; ++i){
            int pi = -1;
            int minCost = INT_MAX;
            for(int j = 0; j < n; ++j){
                if(visited[j] == 0 && key[j] < minCost){
                    minCost = key[j];
                    pi = j;
                }
            }
            visited[pi] = 1;
            cost += key[pi];
            for(int j = 0; j < n; ++j){
                if(visited[j] == 0){
                    int d = distance(points[pi], points[j]);
                    key[j] = min(key[j], d);
                }
            }
        }
        return cost;
    }
    int distance(vector<int>& p1, vector<int>& p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};

class Solution1_1 {//Prim
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        vector<char> visited(n, 0);
        vector<int> key(n, INT_MAX);
        auto cmp = [&](int i, int j){
            return key[i] > key[j];
        };

        vector<int> PQ(n);
        iota(PQ.begin(), PQ.end(), 0);
        key[0] = 0;
        int cost = 0;
        for(int i = 0; i < n-1; ++i){
            make_heap(PQ.begin(), PQ.end()-i, cmp);
            int pi = PQ.front();
            visited[pi] = 1;
            for(int j = 0; j < n; ++j){
                if(visited[j] == 0){
                    int d = distance(points[pi], points[j]);
                    if(d < key[j]){
                        if(key[j] == INT_MAX){
                            cost += d;
                        }else{
                            cost -= (key[j]-d);
                        }
                        key[j] = d;
                    }
                }
            }
            pop_heap(PQ.begin(), PQ.end()-i);
        }
        return cost;
    }
    int distance(vector<int>& p1, vector<int>& p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};

struct Point{
    int p;
    int key;
    Point(){}
    Point(int _p, int _key): p{_p}, key{_key}{}
};

class Solution1_2 {//Prim
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();

        vector<char> visited(n, 0);
        vector<int> key(n, INT_MAX);
        key[0] = 0;
        auto cmp = [&](Point& p1, Point& p2){
            return p1.key > p2.key;
        };
        priority_queue<Point, vector<Point>, decltype(cmp)> PQ(cmp);
        PQ.push(Point(0, 0));
        for(int i = 0; i < n; ++i){
            while(!PQ.empty() && visited[PQ.top().p] == 1){
                PQ.pop();
            }
            int pi = PQ.top().p;
            visited[pi] = 1;
            for(int j = 0; j < n; ++j){
                if(visited[j] == 0){
                    int d = distance(points[pi], points[j]);
                    if(d < key[j]){
                        key[j] = d;
                        PQ.push(Point(j, key[j]));
                    }
                }
            }
        }
        return accumulate(key.begin(), key.end(), 0);
    }
    int distance(vector<int>& p1, vector<int>& p2){
        return abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
    }
};

struct Edge{
    int v1;
    int v2;
    int cost;
    Edge(){}
    Edge(int _v1, int _v2, int _cost):v1{_v1}, v2{_v2}, cost{_cost}{}
};

class Solution2 {//Kruskal
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        vector<Edge> edges;
        edges.reserve(n*(n-1)/2);

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int cost = abs(points[i][0]-points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back(Edge(i, j, cost));
            }
        }

        auto cmp = [](const Edge& e1, const Edge& e2){
            return e1.cost < e2.cost;
        };

        sort(edges.begin(), edges.end(), cmp);

        vector<int> dsj(n);//disjoint-set
        vector<int> set_size(n, 1);
        iota(dsj.begin(), dsj.end(), 0);

        int min_cost = 0;
        int edge_count = 0;
        for(auto& edge: edges){
            if(find(dsj, edge.v1) != find(dsj, edge.v2)){
                union_by_size(dsj, set_size, edge.v1, edge.v2);
                ++edge_count;
                min_cost += edge.cost;
            }
            if(edge_count == n-1){
                break;
            }
        }
        return min_cost;
    }

    int find(vector<int>& dsj, int i){
        if(i == dsj[i]){
            return i;
        }
        dsj[i] = find(dsj, dsj[i]);
        return dsj[i];
    }

    void union_by_size(vector<int>& dsj, vector<int>& set_size, int i, int j){
        i = find(dsj, i);
        j = find(dsj, j);
        if(set_size[i] > set_size[j]){
            dsj[j] = i;
            set_size[j] += set_size[i];
        }else{
            dsj[i] = j;
            set_size[i] += set_size[j];
        }

    }
};