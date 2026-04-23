//#2615 Sum of Distances - https://leetcode.com/problems/sum-of-distances/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> numIdxs;
        int n = nums.size();
        vector<long long> result(n);
        for(int i = 0; i < n; i++)
        {
            numIdxs[nums[i]].push_back(i);
        }
        for(auto &idxs : numIdxs)
        {
            long long total = 0;
            int m = idxs.second.size();
            for(int i = 0; i < m; i++)
                total += idxs.second[i];
            long long sumLeft = 0;
            for(int i = 0; i < m; i++)
            {
                int idx = idxs.second[i];
                result[idx] = total - 2 * sumLeft + idx * (2 * i - m);
                sumLeft += idx;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 3, 1, 1, 2};
    vector<long long> expectedAnswer = {5, 0, 3, 4, 0};
    assert(solution.distance(givenNums) == expectedAnswer);

    givenNums = {0, 5, 3};
    expectedAnswer = {0, 0, 0};
    assert(solution.distance(givenNums) == expectedAnswer);

    return 0;
}
