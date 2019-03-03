//#477 Total Hamming Distance - https://leetcode.com/problems/total-hamming-distance/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0, sum_ones;
        for(int j = 31; j >= 0; j--)
        {
            sum_ones = 0;
            for(int i = 0; i < (int)nums.size(); i++)
            {
                if(nums[i] & (1 << j))
                    sum_ones++;
            }
            result += sum_ones * ((int)nums.size() - sum_ones);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 4, 12};
    int expected_answer = 6;
    assert(solution.totalHammingDistance(given_nums) == expected_answer);

    given_nums = {7, 8, 12, 15};
    expected_answer = 14;
    assert(solution.totalHammingDistance(given_nums) == expected_answer);

    return 0;
}
