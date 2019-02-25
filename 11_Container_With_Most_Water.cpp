//#11 Container With Most Water - https://leetcode.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int MaxArea = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            MaxArea = max(MaxArea, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right])
                right--;
            else
                left++;
        }
        return MaxArea;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int expected_answer = 49;
    assert(solution.maxArea(given_nums) == expected_answer);

    given_nums = {1, 2, 4, 3};
    expected_answer = 4;
    assert(solution.maxArea(given_nums) == expected_answer);

    return 0;
}
