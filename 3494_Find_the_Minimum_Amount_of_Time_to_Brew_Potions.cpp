//#3494 Find the Minimum Amount of Time to Brew Potions - https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> wizardEndTime(n + 1);
        for(int i = 1; i < n + 1; i++)
        {
            wizardEndTime[i] = wizardEndTime[i - 1] + skill[i - 1] * mana[0];
        }
        for(int j =  1; j < m; j++)
        {
            wizardEndTime[0] = wizardEndTime[1];
            long long delay = 0;
            for(int i = 1; i < n + 1; i++)
            {
                if(wizardEndTime[i] > wizardEndTime[i - 1])
                    delay = max(delay, wizardEndTime[i] - wizardEndTime[i - 1]);
                wizardEndTime[i] = wizardEndTime[i - 1] + skill[i - 1] * mana[j];
            }
            for(int i = 0; i < n + 1; i++)
                wizardEndTime[i] += delay;
        }
        return wizardEndTime.back();
    }
};

int main()
{
    Solution solution;
    vector<int> givenSkills = {1, 5 ,2, 4};
    vector<int> givenMana = {5, 1 ,4, 2};
    long long expectedAnswer = 110;
    assert(solution.minTime(givenSkills, givenMana) == expectedAnswer);

    givenSkills = {1, 2, 3, 4};
    givenMana = {1, 2};
    expectedAnswer = 21;
    assert(solution.minTime(givenSkills, givenMana) == expectedAnswer);

    return 0;
}
