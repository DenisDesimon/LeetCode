//#3363 Find the Maximum Number of Fruits Collected - https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int result = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++)
            result += fruits[i][i];
        auto dp = [&]() -> int
        {
            vector<int> prev(n, INT_MIN), cur(n, INT_MIN);
            prev[n - 1] = fruits[0][n - 1];
            for(int i = 1; i < n - 1; i++)
            {
                for(int j = max(n - 1 - i, i + 1); j < n; j++)
                {
                    int maxPrev = prev[j];
                    maxPrev = max(maxPrev, prev[j - 1]);
                    if(j + 1 < n)
                        maxPrev = max(maxPrev, prev[j + 1]);
                    cur[j] = maxPrev + fruits[i][j];
                }
                prev = cur;
            }
            return prev.back();
        };
        result += dp();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
                swap(fruits[j][i], fruits[i][j]);
        }
        result += dp();
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenFruits = {{1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int expectedAnswer = 100;
    assert(solution.maxCollectedFruits(givenFruits) == expectedAnswer);

    givenFruits = {{1, 1}, {1, 1}};
    expectedAnswer = 4;
    assert(solution.maxCollectedFruits(givenFruits) == expectedAnswer);

    return 0;
}
