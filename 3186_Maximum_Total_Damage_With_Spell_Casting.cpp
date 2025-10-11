//#3186 Maximum Total Damage With Spell Casting - https://leetcode.com/problems/maximum-total-damage-with-spell-casting/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int n = power.size();
        vector<long long> memo(n);
        for(int i = 0; i < n; i++)
        {
            long long spellPower = power[i];
            while(i + 1 < n && power[i] == power[i + 1])
                spellPower += power[i++];
            long long maxWithout = 0;
            long long maxWith = spellPower;
            int j = i - 1;
            while(j >= 0 && power[i] <= power[j] + 2)
                maxWithout = max(maxWithout, memo[j--]);
            maxWith = (j >= 0 ? memo[j] : 0) + spellPower;
            memo[i] = max(maxWith, maxWithout);
        }
        return memo.back();
    }
};

int main()
{
    Solution solution;
    vector<int> givenPower = {7, 1, 6, 6};
    long long expectedAnswer = 13;
    assert(solution.maximumTotalDamage(givenPower) == expectedAnswer);

    givenPower = {1, 1, 3, 4};
    expectedAnswer = 6;
    assert(solution.maximumTotalDamage(givenPower) == expectedAnswer);

    return 0;
}
