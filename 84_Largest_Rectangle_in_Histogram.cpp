//#84 Largest Rectangle in Histogram - https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0, length = 0;
        stack<int> high;
        while(length < (int)heights.size())
        {
            if(high.empty() || heights[length] > heights[high.top()])
                high.push(length++);
            else
            {
                auto cur_high = high.top();
                high.pop();
                result = max(result, heights[cur_high] * (high.empty() ? length : length - high.top() - 1));
            }
        }
        while(!high.empty())
        {
            auto cur_high = high.top();
            high.pop();
            result = max(result, heights[cur_high] * (high.empty() ? length : length - high.top() - 1));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_heights = {2, 1, 5, 6, 2, 3};
    int expected_answer = 10;
    assert(solution.largestRectangleArea(given_heights) == expected_answer);

    given_heights = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    expected_answer = 12;
    assert(solution.largestRectangleArea(given_heights) == expected_answer);

    return 0;
}
