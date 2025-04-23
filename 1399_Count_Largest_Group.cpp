//#1399 Count Largest Group - https://leetcode.com/problems/count-largest-group/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> dp(n + 1);
        unordered_map<int, int> count;
        int result = 0;
        int maxSum = 0;
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i / 10] + i % 10;
            count[dp[i]]++;
            maxSum = max(maxSum, count[dp[i]]);
        }
        for(auto &sum : count)
        {
            if(sum.second == maxSum)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 13;
    int expected_answer = 4;
    assert(solution.countLargestGroup(given_n) == expected_answer);

    given_n = 2;
    expected_answer = 2;
    assert(solution.countLargestGroup(given_n) == expected_answer);

    return 0;
}
