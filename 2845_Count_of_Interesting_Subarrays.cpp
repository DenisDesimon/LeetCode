//#2845 Count of Interesting Subarrays - https://leetcode.com/problems/count-of-interesting-subarrays/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long result = 0;
        unordered_map<int, int> countIndexes;
        int curSum = 0;
        countIndexes[0] = 1;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            curSum += nums[i] % modulo == k;
            result += countIndexes[(curSum - k + modulo) % modulo];
            countIndexes[curSum % modulo]++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 2, 4};
    int given_modulo = 2;
    int given_k = 1;
    long long expected_answer = 3;
    assert(solution.countInterestingSubarrays(given_nums, given_modulo, given_k) == expected_answer);

    given_nums = {3, 1, 9, 6};
    given_modulo = 3;
    given_k = 0;
    expected_answer = 2;
    assert(solution.countInterestingSubarrays(given_nums, given_modulo, given_k) == expected_answer);

    return 0;
}
