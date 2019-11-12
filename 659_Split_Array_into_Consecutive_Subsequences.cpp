//#659 Split Array into Consecutive Subsequences - https://leetcode.com/problems/split-array-into-consecutive-subsequences/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> tails;
        for(auto num : nums)
            count[num]++;
        for(auto num : nums)
        {
            if(count[num] == 0)
                continue;
            else if(tails[num] > 0)
            {
                tails[num]--;
                tails[num + 1]++;
            }
            else if(count[num + 1] > 0 && count[num + 2] > 0)
            {
                count[num + 1]--;
                count[num + 2]--;
                tails[num + 3]++;
            }
            else
                return false;
            count[num]--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 3, 4, 4, 5, 5};
    bool expected_answer = true;
    assert(solution.isPossible(given_nums) == expected_answer);

    given_nums = {1, 2, 3, 4, 4, 5};
    expected_answer = false;
    assert(solution.isPossible(given_nums) == expected_answer);

    return 0;
}
