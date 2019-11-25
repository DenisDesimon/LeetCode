//#594 Longest Harmonious Subsequence - https://leetcode.com/problems/longest-harmonious-subsequence/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        int result = 0;
        for(auto num : nums)
        {
            hash[num]++;
            if(hash.count(num + 1))
                result = max(result, hash[num] + hash[num + 1]);
            if(hash.count(num - 1))
                result = max(result, hash[num] + hash[num - 1]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 3, 2, 2, 5, 2, 3, 7};
    int expected_answer = 5;
    assert(solution.findLHS(given_nums) == expected_answer);

    given_nums = {2, 3, 4, 5, 6};
    expected_answer = 2;
    assert(solution.findLHS(given_nums) == expected_answer);

    return 0;
}
