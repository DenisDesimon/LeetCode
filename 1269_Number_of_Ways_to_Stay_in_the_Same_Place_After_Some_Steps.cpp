//#1269 Number of Ways to Stay in the Same Place After Some Steps - https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int  backtrack(int cur_step, int cur_x, int& steps, vector<vector<int>>& memo, int& n){
        if(steps - cur_step < cur_x)
            return 0;
        if(cur_step == steps)
            return cur_x == 0;
        if(memo[cur_x][cur_step])
            return memo[cur_x][cur_step];
        long long left = 0, right = 0, stay = 0;
        if(cur_x != 0)
            left = backtrack(cur_step + 1, cur_x - 1, steps, memo, n);
        if(cur_x != n - 1)
            right = backtrack(cur_step + 1, cur_x + 1, steps, memo, n);
        stay = backtrack(cur_step + 1, cur_x, steps, memo, n);
        return memo[cur_x][cur_step] = (left + right  + stay) % (long long)(1e9 + 7);
    }
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> memo(min(steps / 2 + 1, arrLen), vector<int>(steps, 0));
        return backtrack(0, 0, steps, memo, arrLen);
    }
};

int main()
{
    Solution solution;
    int given_steps = 438;
    int given_len = 315977;
    int expected_answer = 483475137;
    assert(solution.numWays(given_steps, given_len) == expected_answer);

    given_steps = 2;
    given_len = 4;
    expected_answer = 2;
    assert(solution.numWays(given_steps, given_len) == expected_answer);

    return 0;
}
