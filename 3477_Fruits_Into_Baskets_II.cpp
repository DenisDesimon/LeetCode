//#3477 Fruits Into Baskets II - https://leetcode.com/problems/fruits-into-baskets-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        for(auto &fruit : fruits)
        {
            int i = 0;
            for(; i < (int)baskets.size(); i++)
            {
                if(baskets[i] >= fruit)
                {
                    baskets[i] = 0;
                    break;
                }
            }
            if(i == (int)baskets.size())
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenFruits = {4, 2, 5};
    vector<int> givenBaskets = {3, 5, 4};
    int expectedAnswer = 1;
    assert(solution.numOfUnplacedFruits(givenFruits, givenBaskets) == expectedAnswer);

    givenFruits = {3, 6, 1};
    givenBaskets = {6, 4, 7};
    expectedAnswer = 0;
    assert(solution.numOfUnplacedFruits(givenFruits, givenBaskets) == expectedAnswer);

    return 0;
}
