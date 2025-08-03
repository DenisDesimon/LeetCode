//#2561 Rearranging Fruits - https://leetcode.com/problems/rearranging-fruits/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, long long> frequency;
        int minFruit = INT_MAX;
        long long result = 0;
        for(auto &fruit : basket1)
        {
            frequency[fruit]++;
            minFruit = min(fruit, minFruit);
        }
        for(auto &fruit : basket2)
        {
            frequency[fruit]--;
            minFruit = min(fruit, minFruit);
        }
        vector<int> sortedToSwapFruits;
        for(auto &[first, second] : frequency)
        {
            if(second % 2 != 0)
                return - 1;
            for(int i = 0; i < abs(second) / 2; i++)
                sortedToSwapFruits.push_back(first);
        }
        nth_element(sortedToSwapFruits.begin(), sortedToSwapFruits.begin() + sortedToSwapFruits.size() / 2,sortedToSwapFruits.end());
        for(int i = 0; i < (int)sortedToSwapFruits.size() / 2; i++)
        {
            result += min(sortedToSwapFruits[i], 2 * minFruit);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenBasket1 = {4, 2, 2, 2};
    vector<int> givenBasket2 = {1, 4, 1, 2};
    int expectedAnswer = 1;
    assert(solution.minCost(givenBasket1, givenBasket2) == expectedAnswer);

    givenBasket1 = {2, 3, 4, 1};
    givenBasket2 = {3, 2, 5, 1};
    expectedAnswer = -1;
    assert(solution.minCost(givenBasket1, givenBasket2) == expectedAnswer);

    return 0;
}
