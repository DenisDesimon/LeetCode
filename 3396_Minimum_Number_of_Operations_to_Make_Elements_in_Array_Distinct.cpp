//#3396 Minimum Number of Operations to Make Elements in Array Distinct - https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<bool> isNumBehind(101, false);
        for(int i = (int)nums.size() - 1; i >= 0; i--)
        {
            if(isNumBehind[nums[i]])
                return i / 3 + 1;
            isNumBehind[nums[i]] = true;
        }
        return 0;
    }
};

int main()
{
    Solution solution;

    vector<int> given_nums = {5, 7, 11, 12, 12};
    int expected_answer = 2;
    assert(solution.minimumOperations(given_nums) == expected_answer);

    given_nums = {4, 5, 6, 4, 4};
    expected_answer = 2;
    assert(solution.minimumOperations(given_nums) == expected_answer);

    return 0;
}
