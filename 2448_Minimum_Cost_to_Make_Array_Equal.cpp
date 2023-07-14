#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <memory>

using namespace std;


class Solution 
{
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        const int n = nums.size();

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), 
             indices.end(), 
             [&](int i, int j){return nums[i] < nums[j];});
                     
        sort(nums.begin(), nums.end());
        
        vector<int> sortedCost(n);
        for (int i = 0; i < n; ++i) 
        {
            sortedCost[i] = cost[indices[i]];
        }

        long long sum = 0;
        vector<long long> costPrefixSum(n);
        for(int i = 0; i < n; ++i)
        {
            sum += sortedCost[i];
            costPrefixSum[i] = sum;
        }       

        long long totalCost = 0;
        for(int i = 1; i < n; ++i)
        {
            totalCost += static_cast<long long>(nums[i]-nums[0])*sortedCost[i];
        }

        long long minTotalCost = totalCost;

        for(int i = 1; i < n; ++i)
        {
            long long deltaX = nums[i]-nums[i-1];
            totalCost +=  deltaX * costPrefixSum[i-1];
            totalCost -=  deltaX * (costPrefixSum[n-1] - costPrefixSum[i-1]);
            if(totalCost < minTotalCost)
            {
                minTotalCost = totalCost;
            }
        }
        return minTotalCost;
    }
};

void example()
{
    std::vector<int> A = {5, 3, 1, 4, 2};  // 第一個向量 A
    std::vector<int> B = {9, 7, 8, 6, 10};  // 第二個向量 B

    // 建立索引向量
    std::vector<int> indices(A.size());
    std::iota(indices.begin(), indices.end(), 0);

    // 使用自訂排序函式對索引向量進行排序
    std::sort(indices.begin(), indices.end(), [&](int i, int j) {
        return A[i] < A[j];
    });

    // 根據排序後的索引重新排列向量 B
    std::vector<int> sortedB(B.size());
    for (size_t i = 0; i < indices.size(); i++) {
        sortedB[i] = B[indices[i]];
    }

    // 更新向量 B
    B = sortedB;

    // 打印排序後的向量 A 和 B
    std::cout << "排序後的向量 A: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "排序後的向量 B: ";
    for (int num : B) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void arrangement()
{
    std::vector<int> A = {2, 4, 3, 5, 6};  // 第一個向量 A
    std::vector<int> B = {9, 7, 8, 6, 10};  // 第二個向量 B
    auto cmp = [&](int i, int j) -> bool {return A[i] < A[j];};

    std::vector<int> indices(A.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), cmp);
    std::sort(A.begin(), A.end());

    // 根據排序後的索引重新排列向量 B
    std::vector<int> sortedB(B.size());
    for (size_t i = 0; i < indices.size(); i++) {
        sortedB[i] = B[indices[i]];
    }

    // 更新向量 B
    B = sortedB;

    // 打印排序後的向量 A 和 B
    std::cout << "排序後的向量 A: ";
    for (int num : A) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "排序後的向量 B: ";
    for (int num : B) {
        std::cout << num << " ";
    }
    std::cout << std::endl;


}

int main() 
{
    arrangement();

    return 0;
}