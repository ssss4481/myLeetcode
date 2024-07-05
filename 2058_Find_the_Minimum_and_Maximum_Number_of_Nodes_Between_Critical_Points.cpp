#include <vector>
#include <algorithm>
#include <iostream>
#include "ListNode.hpp"

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

using namespace std;


class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == nullptr){
            return {-1, -1};
        }

        int prev_critical_pos = -1;
        int first_critical_pos = -1;
        int current_pos = 0;
        int prev_value = head->val;

        int min_distance = INT_MAX;
        int max_distance = -1;

        while(head->next != nullptr){
            if((head->val > prev_value && head->val > head->next->val) ||
                (head->val < prev_value && head->val < head->next->val))
            {
                if(prev_critical_pos != -1){
                    min_distance = min(min_distance, current_pos-prev_critical_pos);
                    max_distance = current_pos - first_critical_pos;
                }else{
                    first_critical_pos = current_pos;
                }
                prev_critical_pos = current_pos;
            }
            ++current_pos;
            prev_value = head->val;
            head = head->next;
        }

        if(max_distance == -1){
            return {-1, -1};
        }

        return {min_distance, max_distance};
    }

};


class Solution1 {//too slow
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        trace(head, head->val, 0, pos);

        vector<int> result = {-1, -1};
        if(pos.size() < 2){
            return result;
        }

        result[1] = pos.front() - pos.back();
        result[0] = INT_MAX;
        for(int i = 0; i < pos.size()-1; ++i){
            result[0] = min(result[0], pos[i]-pos[i+1]);
        }
        return result;
    }

    int trace(ListNode* pNode, int prev, int index, vector<int>& pos){
        if(pNode == nullptr){
            return prev;
        }

        int next = trace(pNode->next, pNode->val, index+1, pos);

        if((prev > pNode->val && next > pNode->val) || (prev < pNode->val && next < pNode->val)){
            pos.emplace_back(index);
        }

        return pNode->val;
    }
};