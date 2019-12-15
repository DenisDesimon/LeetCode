//#1291 Sequential Digits - https://leetcode.com/problems/sequential-digits/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> nums;
        vector<int> result;
        for(int i = 1; i < 10; i++)
            nums.push(i);
        while(!nums.empty())
        {
            int cur_num = nums.front();
            nums.pop();
            if(cur_num >= low && cur_num <= high)
                result.push_back(cur_num);
            else if(cur_num > high)
                break;
            int digit = cur_num % 10;
            if(digit < 9)
                nums.push(cur_num * 10 + digit++ + 1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_low = 100;
    int given_high = 300;
    vector<int> expected_answer = {123, 234};
    assert(solution.sequentialDigits(given_low, given_high) == expected_answer);

    given_low = 1000;
    given_high = 13000;
    expected_answer = {1234, 2345, 3456, 4567, 5678, 6789, 12345};
    assert(solution.sequentialDigits(given_low, given_high) == expected_answer);

    return 0;
}
