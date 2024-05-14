#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {//O(2n)
public:
    vector<int> partitionLabels(string s) {
        const int n = s.size();
        unordered_map<char, int> last_show_pos;
        for(int i = 0; i < n; ++i){
            last_show_pos[s[i]] = i;
        }

        int start = 0;
        vector<int> res;
        int last = 0;
        for(int i = 0; i < n; ++i){
            last = max(last, last_show_pos[s[i]]);
            if(last == i){
                res.push_back(last-start+1);
                start = i+1;
            }
        }
        return res;
    }
};



class Solution {//O(n) + O(1)
public:
    vector<int> partitionLabels(string s) {
        const int n = s.size();
        vector<vector<int>> intervals(26, {n, -1});
        for(int i = 0; i < n; ++i){
            intervals[s[i]-'a'][0] = min(intervals[s[i]-'a'][0], i);
            intervals[s[i]-'a'][1] = max(intervals[s[i]-'a'][1], i);
        }

        auto cmp = [](const vector<int>& v1, const vector<int>& v2){
            return v1.front() < v2.front();
        };

        sort(intervals.begin(), intervals.end(), cmp);

        auto overlapping = [](const vector<int>& v1, const vector<int>& v2){
            return !(v1.back() < v2.front() || v1.front() > v2.back());
        };

        vector<vector<int>> combined_result;
        vector<int> cur = {};

        int end;
        for(end = 0; end < 26; ++end){
            if(intervals[end][0] == n){
                break;
            }
        }

        for(int i = 0; i < end; ++i){
            if(cur.empty()){
                cur = intervals[i];
                continue;
            }
            if(overlapping(cur, intervals[i])){
                cur.front() = min(cur.front(), intervals[i].front());
                cur.back() = max(cur.back(), intervals[i].back());
            }else{
                combined_result.push_back(cur);
                cur = intervals[i]; 
            }
        }
        combined_result.push_back(cur);

        vector<int> res;

        for(auto& v : combined_result){
            res.push_back(v[1]-v[0]+1);
        }
        return res;
    }
};