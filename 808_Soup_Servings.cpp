//#808 Soup Servings - https://leetcode.com/problems/soup-servings/
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <cassert>
using namespace std;

class Solution {
    double brute(int soupA, int soupB, unordered_map<int, unordered_map<int, double>> &memo){
        if(memo[soupA].count(soupB))
            return memo[soupA][soupB];
        if(soupA <= 0 && soupB <= 0)
            return 0.5;
        if(soupA <= 0)
            return 1;
        if(soupB <= 0)
            return 0;
        return memo[soupA][soupB] = (brute(soupA - 4, soupB, memo) + brute(soupA - 3, soupB - 1, memo) + brute(soupA - 2, soupB - 2, memo) + brute(soupA - 1, soupB - 3, memo)) / 4;
    }
public:
    double soupServings(int n) {
        unordered_map<int, unordered_map<int, double>> memo;
        int m = ceil(n / 25.0);
        for (int k = 1; k <= m; k++)
        {
            if(brute(k, k, memo) > 1 - 1e-5)
                return 1;
        }
        return brute(m, m, memo);

    }
};

int main()
{
    Solution solution;
    int givenN = 100;
    double expectedAnswer = 0.71875;
    assert(solution.soupServings(givenN) == expectedAnswer);

    givenN = 660295675;
    expectedAnswer = 1;
    assert(solution.soupServings(givenN) == expectedAnswer);

    return 0;
}
