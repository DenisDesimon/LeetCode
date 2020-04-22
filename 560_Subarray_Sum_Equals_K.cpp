//#560 Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int Prefix = 0, result = 0;
        unordered_map<int, int> hash;
        hash[0]++;
        for(auto& num : nums)
        {
            Prefix += num;
            if(hash.count(Prefix - k))
                result += hash[Prefix - k];
            hash[Prefix]++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int given_k = 0;
    int expected_answer = 55;
    assert(solution.subarraySum(given_nums, given_k) == expected_answer);

    given_nums = {1, 1, 1};
    given_k = 2;
    expected_answer = 2;
    assert(solution.subarraySum(given_nums, given_k) == expected_answer);

    return 0;
}
