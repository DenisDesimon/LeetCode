//#3147 Taking Maximum Energy From the Mystic Dungeon - https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> memo(n);
        int result = INT_MIN;
        for(int i = n - 1; i >= 0; i--)
        {
            if(i + k >= n)
                memo[i] = energy[i];
            else
                memo[i] = energy[i] + memo[i + k];
            result = max(result, memo[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenEnergy = {5, 2, -10, -5, 1};
    int givenK = 3;
    int expectedAnswer = 3;
    assert(solution.maximumEnergy(givenEnergy, givenK) == expectedAnswer);

    givenEnergy = {-2, -3, -1};
    givenK = 2;
    expectedAnswer = -1;
    assert(solution.maximumEnergy(givenEnergy, givenK) == expectedAnswer);

    return 0;
}
