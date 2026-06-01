//#3946 Maximum Number of Items From Sale I - https://leetcode.com/problems/maximum-number-of-items-from-sale-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> count(n, 1);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                if(items[j][0] % items[i][0] == 0)
                    count[i]++;
            }
        }
        vector<int> prev(budget + 1, 0);
        for(int i = 0; i < n; i++)
        {
            vector<int> next = prev;
            int curCost = items[i][1];
            for(int spent = budget; spent >= curCost; spent--)
            {
                next[spent] = max(next[spent], prev[spent - curCost] + count[i]);
            }

            for(int spent = curCost; spent <= budget; spent++)
            {
                next[spent] = max(next[spent], next[spent - curCost] + 1);
            }

            prev.swap(next);
        }
        return prev.back();
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenItems = {{6, 2}, {2, 6}, {3, 4}};
    int givenBudget = 9;
    int expectedAnswer = 4;
    assert(solution.maximumSaleItems(givenItems, givenBudget) == expectedAnswer);

    givenItems = {{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
    givenBudget = 8;
    expectedAnswer = 10;
    assert(solution.maximumSaleItems(givenItems, givenBudget) == expectedAnswer);

    return 0;
}
