#include <vector>
#include <unordered_map>
#include <iostream>

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;

class DetectSquares {
private:
    vector<vector<int>> points;
    unordered_map<string, int> hashmap;
    

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        int x = point.front();
        int y = point.back();
        string key = to_string(x) + "," + to_string(y);
        ++hashmap[key];
    }
    
    int count(vector<int> point) {
        int x = point.front();
        int y = point.back();
        int res = 0;
        for(auto& p: points){
            int px = p.front();
            int py = p.back();

            if(px == x || py == y || abs(px-x) != abs(py-y)){
                continue;
            }
            string key1 = to_string(x) + "," + to_string(py);
            string key2 = to_string(px) + "," + to_string(y);
            res += hashmap[key1]*hashmap[key2];
        }

        return res;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */