#include <iostream>
#include <vector>


int maxArea(std::vector<int>& height)
{
    //initialization
    uint li = 0;
    uint ri = height.size()-1;
    uint ans = 0;
    while(li < ri)
    {
        uint limit = height[li] >= height[ri] ? height[ri] : height[li];
        ans = (limit * (ri-li) > ans ?  (limit)*(ri-li) : ans);
        height[li] >= height[ri] ? --ri : ++li ;
    }
    return ans;
}


int main()
{
    std::vector<int> height1 {1,8,6,2,5,4,8,3,7};
    std::vector<int> height2 {1,2,4,3};
    std::vector<int> height3 {2,3,10,5,7,8,9};
    std::vector<int> height4 {1,1};
    std::vector<int> height5 {2,3,4,5,18,17,6};
    std::cout << maxArea(height1) << "\n";
    std::cout << maxArea(height2) << "\n";
    std::cout << maxArea(height3) << "\n";
    std::cout << maxArea(height4) << "\n";
    std::cout << maxArea(height5) << "\n";

    return 0;
}