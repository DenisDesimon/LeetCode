//#453 Minimum Moves to Equal Array Elements - https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result = 0;
        int min_elem = *min_element(nums.begin(), nums.end());
        for(auto& num : nums)
        {
            if(num != min_elem)
                result += num - min_elem;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    int expected_answer = 3;
    assert(solution.minMoves(given_nums) == expected_answer);

    given_nums = {4, 2, 3, 9, 3};
    expected_answer = 11;
    assert(solution.minMoves(given_nums) == expected_answer);

    return 0;
}
