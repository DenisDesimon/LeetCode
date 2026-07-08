//#3756 Concatenate Non-Zero Digits and Multiply by Sum II - https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int MOD = 1e9 + 7;
const int N = 100001;
long long powTen[N];

int init = [](){
    powTen[0] = 1;
    for(int i = 1; i < N; i++)
    {
        powTen[i] = (powTen[i - 1] * 10) % MOD;
    }
    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int> sum(n + 1);
        vector<long long> x(n + 1);
        vector<int> count(n + 1);
        vector<int> result(m);
        for(int i = 0; i < n; i++)
        {
            int dig = s[i] - '0';
            sum[i + 1] = sum[i] + dig;
            x[i + 1] = dig > 0 ? (x[i] * 10 + dig) % MOD : x[i];
            count[i + 1] = count[i] + (dig > 0);
        }
        for(int i = 0; i < m; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1] + 1;
            int length = count[r] - count[l];
            long long curX = (x[r] - x[l] * powTen[length] % MOD + MOD) % MOD;
            long long curSum = sum[r] - sum[l];
            result[i] = curX * curSum % MOD;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "10203004";
    vector<vector<int>> givenQueries = {{0, 7}, {1, 3}, {4, 6}};
    vector<int> expectedAnswer = {12340, 4, 9};
    assert(solution.sumAndMultiply(givenS, givenQueries) == expectedAnswer);

    givenS = "1000";
    givenQueries = {{0, 3}, {1, 1}};
    expectedAnswer = {1, 0};
    assert(solution.sumAndMultiply(givenS, givenQueries) == expectedAnswer);

    return 0;
}
