//#2099 Find Subsequence of Length K With the Largest Sum - https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numIdx;
        vector<int> result;
        for(int i = 0; i < k; i++)
        {
            auto idx = upper_bound(numIdx.begin(), numIdx.end(), make_pair(nums[i], i));
            numIdx.insert(idx, {nums[i], i});
        }
        for(int i = k; i < (int)nums.size(); i++)
        {
             auto idx = upper_bound(numIdx.begin(), numIdx.end(), make_pair(nums[i], i));
             if(idx > numIdx.end() - k)
                 numIdx.insert(idx, {nums[i], i});
        }
        sort(numIdx.end() - k, numIdx.end(), [](pair<int, int> &a, pair<int, int> &b){return a.second < b.second;});
        for(int i = numIdx.size() - k; i < (int)numIdx.size(); i++)
            result.push_back(numIdx[i].first);
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> given_nums = {2, 1, 3, 3};
    int given_k = 2;
    vector<int> expected_answer = {3, 3};
    assert(solution.maxSubsequence(given_nums, given_k) == expected_answer);

    given_nums = {-1, -2, 3, 4};
    given_k = 3;
    expected_answer = {-1, 3, 4};
    assert(solution.maxSubsequence(given_nums, given_k) == expected_answer);

    return 0;
}
