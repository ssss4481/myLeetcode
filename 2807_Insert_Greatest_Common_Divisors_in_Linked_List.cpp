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
    int find_gcd(int a, int b){
        do{
            a %= b;
            swap(a, b);
        }while(b != 0);
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto current = head;

        while(current->next != nullptr){
            auto next = current->next;
            int gcd = find_gcd(current->val, next->val);
            current->next = new ListNode(gcd, next);
            current = next;
        }

        return head;
    }
};