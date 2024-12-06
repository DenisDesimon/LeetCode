//#2554 Maximum Number of Integers to Choose From a Range I - https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banSet(banned.begin(), banned.end());
        int result = 0;
        for(int i = 1; i <= n; i++)
        {
            if(banSet.count(i))
                continue;
            maxSum -= i;
            if(maxSum < 0)
                return result;
            result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;

    vector<int> given_banned = {1, 6, 5};
    int given_n = 5;
    int given_maxSum = 6;
    int expected_answer = 2;
    assert(solution.maxCount(given_banned, given_n, given_maxSum) == expected_answer);

    given_banned = {11};
    given_n = 7;
    given_maxSum = 50;
    expected_answer = 7;
    assert(solution.maxCount(given_banned, given_n, given_maxSum) == expected_answer);

    return 0;
}
