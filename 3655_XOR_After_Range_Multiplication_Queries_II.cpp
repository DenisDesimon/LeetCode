//#3655 XOR After Range Multiplication Queries II - https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/
#include <iostream>
#include <cassert>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
    int fastPow(long long num, int pow)
    {
        long long result = 1;
        while(pow)
        {
            if(pow & 1)
                result = (result * num) % mod;
            num = (num * num) % mod;
            pow >>= 1;
        }
        return result;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int threshold = sqrt(n);
        vector<vector<vector<int>>> groups(threshold);
        for(auto &query : queries)
        {
            int l = query[0], r = query[1], k = query[2], v = query[3];
            if(k < threshold)
                groups[k].push_back({l, r, v});
            else
            {
                for(int i = l; i <= r; i += k)
                    nums[i] = (long long)nums[i] * v % mod;
            }
        }
        vector<long long> dif(n + threshold);
        for(int k = 1; k < threshold; k++)
        {
            if(groups[k].empty())
                continue;
            fill(dif.begin(), dif.end(), 1);
            for(auto &group : groups[k])
            {
                int l = group[0], r = group[1], v = group[2];
                dif[l] = dif[l] * v % mod;
                int upperBound = ((r - l) / k + 1) * k + l;
                dif[upperBound] = dif[upperBound] * fastPow(v, mod - 2) % mod;
            }
            for(int i = k; i < n; i++)
            {
                dif[i] = dif[i] * dif[i - k] % mod;
            }
            for(int i = 0; i < n; i++)
            {
                nums[i] = (long long)nums[i] * dif[i] % mod;
            }
        }
        int result = 0;
        for(auto &num : nums)
            result ^= num;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 1};
    vector<vector<int>> givenQueries = {{0, 2, 1, 4}};
    int expected_answer = 4;
    assert(solution.xorAfterQueries(givenNums, givenQueries) == expected_answer);

    givenNums = {2, 3, 1, 5, 4};
    givenQueries = {{1, 4, 2, 3}, {0, 2, 1, 2}};
    expected_answer = 31;
    assert(solution.xorAfterQueries(givenNums, givenQueries) == expected_answer);

    return 0;
}
