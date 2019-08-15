//#128 Longest Consecutive Sequence - https://leetcode.com/problems/longest-consecutive-sequence/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int result = 0;
        for(auto num : nums)
        {
            if(hash[num] != 0)
                continue;
            int left = hash[num - 1], right = hash[num + 1];
            hash[num] = hash[num - left] = hash[num + right] = hash[num] + hash[num - 1] + hash[num + 1] + 1;
            result = max(result, hash[num]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int expected_answer = 9;
    assert(solution.longestConsecutive(given_nums) == expected_answer);

    given_nums = {100, 4, 200, 1, 3, 2};
    expected_answer = 4;
    assert(solution.longestConsecutive(given_nums) == expected_answer);

    return 0;
}
