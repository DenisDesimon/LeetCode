//#303 Range Sum Query - Immutable - https://leetcode.com/problems/range-sum-query-immutable/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class NumArray {
    vector<int> PrefixSum;
public:
    NumArray(vector<int>& nums) {
        PrefixSum.resize(nums.size() + 1);
        PrefixSum[0] = 0;
        for(int i = 1; i < (int)nums.size() + 1; i++)
        {
            PrefixSum[i] += PrefixSum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return PrefixSum[j + 1] - PrefixSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

int main()
{
    vector<int> given_nums = {-2, 0, 3, -5, 2, -1};
    NumArray solution(given_nums);

    int expected_answer = 1;
    assert(solution.sumRange(0, 2) == expected_answer);

    expected_answer = -1;
    assert(solution.sumRange(2, 5) == expected_answer);

    expected_answer = -3;
    assert(solution.sumRange(0, 5) == expected_answer);

    return 0;
}
