//#3653 XOR After Range Multiplication Queries I - https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        for(auto &query : queries)
        {
            for(int i = query[0]; i <= query[1]; i += query[2])
            {
                nums[i] = ((long long)nums[i] * query.back()) % mod;
            }
        }
        int result = 0;
        for(auto &num : nums)
            result ^= num;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 1};
    vector<vector<int>> givenQueries = {{0, 2, 1, 4}};
    int expected_answer = 4;
    assert(solution.xorAfterQueries(givenNums, givenQueries) == expected_answer);

    givenNums = {2, 3, 1, 5, 4};
    givenQueries = {{1, 4, 2, 3}, {0, 2, 1, 2}};
    expected_answer = 31;
    assert(solution.xorAfterQueries(givenNums, givenQueries) == expected_answer);

    return 0;
}
