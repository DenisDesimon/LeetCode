//#3312 Sorted GCD Pair Queries - https://leetcode.com/problems/sorted-gcd-pair-queries/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxNum = INT_MIN;
        for(auto &num : nums)
            maxNum = max(maxNum, num);
        vector<long long> count(maxNum + 1);
        vector<int> result;
        for(auto &num : nums)
            count[num]++;
        for(int i = 1; i <= maxNum; i++)
        {
            for(int j = 2 * i; j <= maxNum; j += i)
                count[i] += count[j];
        }
        for(int i = 1; i <= maxNum; i++)
        {
            count[i] = count[i] * (count[i] - 1) / 2;
        }
        for(int i = maxNum; i > 0; i--)
        {
            for(int j = 2 * i; j <= maxNum; j += i)
                count[i] -= count[j];
        }
        for(int i = 2; i <= maxNum; i++)
            count[i] += count[i - 1];
        for(auto &query : queries)
        {
            query++;
            int pos = lower_bound(count.begin(), count.end(), query) - count.begin();
            result.push_back(pos);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 3, 4};
    vector<long long> givenQueries = {0, 2, 2};
    vector<int> expectedAnswer = {1, 2, 2};
    assert(solution.gcdValues(givenNums, givenQueries) == expectedAnswer);

    givenNums = {4, 4, 2, 1};
    givenQueries = {5, 3, 1, 0};
    expectedAnswer = {4, 2, 1, 1};
    assert(solution.gcdValues(givenNums, givenQueries) == expectedAnswer);

    return 0;
}
