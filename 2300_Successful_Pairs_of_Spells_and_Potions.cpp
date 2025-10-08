//#2300 Successful Pairs of Spells and Potions - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> result;
        for(auto &spell : spells)
        {
            long long minPotionPower = success / spell;
            if(success % spell)
                minPotionPower++;
            auto pos = lower_bound(potions.begin(), potions.end(), minPotionPower);
            result.push_back(potions.size() - (pos - potions.begin()));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenSpells = {5, 1, 3};
    vector<int> givenPotions = {1, 2, 3, 4, 5};
    long long givenSuccess = 7;
    vector<int> expectedAnswer = {4, 0, 3};
    assert(solution.successfulPairs(givenSpells, givenPotions, givenSuccess) == expectedAnswer);

    givenSpells = {3, 1, 2};
    givenPotions = {8, 5, 8};
    givenSuccess = 16;
    expectedAnswer = {2, 0, 2};
    assert(solution.successfulPairs(givenSpells, givenPotions, givenSuccess) == expectedAnswer);

    return 0;
}
