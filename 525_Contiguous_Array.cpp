//#525 Contiguous Array - https://leetcode.com/problems/contiguous-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> hash;
        int sum = 0;
        hash[0] = -1;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if(hash.count(sum))
                result = max(result, i - hash[sum]);
            else
                hash[sum] = i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 1};
    int expected_answer = 2;
    assert(solution.findMaxLength(given_nums) == expected_answer);

    given_nums = {0, 1, 0};
    expected_answer = 2;
    assert(solution.findMaxLength(given_nums) == expected_answer);

    return 0;
}
