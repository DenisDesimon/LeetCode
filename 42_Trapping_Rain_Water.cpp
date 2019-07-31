//42 Trapping Rain Water - https://leetcode.com/problems/trapping-rain-water/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
       int left = 0, right = height.size() - 1, left_max = 0, right_max = 0, result = 0;
       while(left < right)
       {
           if(height[left] < height[right])
           {
               if(height[left] >= left_max)
                   left_max = height[left++];
               else
                   result += left_max - height[left++];
           }
           else
           {
               if(height[right] >= right_max)
                   right_max = height[right--];
               else
                   result += right_max - height[right--];
           }
       }
       return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_height = {4, 2, 3};
    int expected_answer = 1;
    assert(solution.trap(given_height) == expected_answer);

    given_height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    expected_answer = 6;
    assert(solution.trap(given_height) == expected_answer);

    return 0;
}
