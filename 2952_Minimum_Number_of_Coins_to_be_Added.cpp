//#2952 Minimum Number of Coins to be Added - https://leetcode.com/problems/minimum-number-of-coins-to-be-added/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int result = 0;
        int currentReach = 0;
        sort(coins.begin(), coins.end());
        for(auto &coin : coins)
        {
            while(currentReach + 1 < coin)
            {
                result++;
                currentReach += currentReach + 1;
                if(currentReach >= target)
                    return result;
            }
            currentReach += coin;
            if(currentReach >= target)
                return result;

        }
        while(currentReach < target){
            result++;
            currentReach += currentReach + 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_coins = {1, 4, 10};
    int given_target = 19;
    int expected_answer = 2;
    assert(solution.minimumAddedCoins(given_coins, given_target) == expected_answer);

    given_coins = {1, 4, 10, 5, 7, 19};
    given_target = 19;
    expected_answer = 1;
    assert(solution.minimumAddedCoins(given_coins, given_target) == expected_answer);

    return 0;
}
