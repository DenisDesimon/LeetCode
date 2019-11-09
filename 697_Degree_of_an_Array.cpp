//#697 Degree of an Array - https://leetcode.com/problems/degree-of-an-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto num : nums)
            hash[num]++;
        int max = 0;
        for(auto pair : hash)
        {
            if(pair.second > max)
            {
                max = pair.second;
            }
        }
        int result = INT_MAX;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(hash[nums[i]] == max)
            {
                int j = i;
                while(max)
                {
                    if(nums[j] == nums[i])
                        max--;
                    j++;
                }
                result = min(result, j - i);
                max = hash[nums[i]];
                hash[nums[i]]--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 2, 3, 1};
    int expected_answer = 2;
    assert(solution.findShortestSubArray(given_nums) == expected_answer);

    given_nums = {1, 2, 2, 3, 1, 4, 2};
    expected_answer = 6;
    assert(solution.findShortestSubArray(given_nums) == expected_answer);

    return 0;
}
