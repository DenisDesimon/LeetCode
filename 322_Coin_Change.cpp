//#322 Coin Change - https://leetcode.com/problems/coin-change/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> value(amount + 1, 0);
        for (int cur_amount = 1; cur_amount <= amount; cur_amount++)
        {
            value[cur_amount] = 1e9;
            for (auto coin : coins)
            {
               if (cur_amount - coin >= 0)
                  value[cur_amount] = min(value[cur_amount], value[cur_amount - coin] + 1);
            }
        }
        if(value[amount] == 1e9)
            return -1;
        return value[amount];
                                                    }


    //solving with recursion
    int solve(int cur_amount, vector<int>& coins, vector<bool> &ready, vector<int> &value){
        if(cur_amount < 0)
            return 1e9;
        if(cur_amount == 0)
            return 0;
        if(ready[cur_amount])
            return value[cur_amount];

        int best = 1e9;
        for(auto c : coins)
        {
           best = min(best, solve(cur_amount - c, coins, ready, value) + 1);
        }

        value[cur_amount] = best;
        ready[cur_amount] = true;
        return best;
                                                                                            }
public:
    int coinChange_recursion(vector<int>& coins, int amount) {
        vector<bool> ready(amount + 1,false);
        vector<int> value(amount + 1,0);
        int result = solve(amount, coins, ready, value);

        if(result >= 1e9)
            return -1;
        else
            return result;

    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 5};
    int given_amount = 11;
    int  expected_answer = 3;
     assert(solution.coinChange(given_nums, given_amount) == expected_answer);
     assert(solution.coinChange_recursion(given_nums, given_amount) == expected_answer);

    given_nums = {2};
    given_amount = 3;
    expected_answer = -1;
    assert(solution.coinChange(given_nums, given_amount) == expected_answer);
    assert(solution.coinChange_recursion(given_nums, given_amount) == expected_answer);

    return 0;
}
