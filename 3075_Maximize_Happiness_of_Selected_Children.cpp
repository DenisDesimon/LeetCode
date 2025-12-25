//#3075 Maximize Happiness of Selected Children - https://leetcode.com/problems/maximize-happiness-of-selected-children/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long result = 0;
        for(int i = 0; i < k; i++)
        {
            if(happiness[i] - i <= 0)
                break;
            result += happiness[i] - i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenHappiness = {1, 2, 3};
    int givenK = 2;
    int expectedAnswer = 4;
    assert(solution.maximumHappinessSum(givenHappiness, givenK) == expectedAnswer);

    givenHappiness = {2, 3, 4, 5};
    givenK = 1;
    expectedAnswer = 5;
    assert(solution.maximumHappinessSum(givenHappiness, givenK) == expectedAnswer);

    return 0;
}
