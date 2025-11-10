//#3542 Minimum Operations to Convert All Elements to Zero - https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/
#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
       stack<int> prev;
       int result = 0;
       for(auto &num: nums)
       {
           while(!prev.empty() && prev.top() > num)
               prev.pop();
           if(num == 0)
               continue;
           if(prev.empty() || prev.top() < num)
           {
               result++;
               prev.push(num);
           }
       }
       return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {3, 1, 2, 1};
    int expectedAnswer = 3;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    givenNums = {1, 2, 1, 2, 1, 2};
    expectedAnswer = 4;
    assert(solution.minOperations(givenNums) == expectedAnswer);

    return 0;
}
