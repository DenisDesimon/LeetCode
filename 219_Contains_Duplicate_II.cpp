//#219 Contains Duplicate II - https://leetcode.com/problems/contains-duplicate-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(hash.count(nums[i]))
            {
                if(i - hash[nums[i]] <= k)
                    return true;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 1};
    int given_k = 3;
    bool expected_answer = true;
    assert(solution.containsNearbyDuplicate(given_nums, given_k) == expected_answer);

    given_nums = {1, 2, 3, 1, 2, 3};
    given_k = 2;
    expected_answer = false;
    assert(solution.containsNearbyDuplicate(given_nums, given_k) == expected_answer);

    return 0;
}
