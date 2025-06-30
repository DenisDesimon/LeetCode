//#2929 Distribute Candies Among Children II - https://leetcode.com/problems/distribute-candies-among-children-ii/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long result = 0;
        for(int i = 0; i <= min(n, limit); i++)
        {
            if(n - i > limit * 2)
                continue;
            result += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return result;
    }
};


int main()
{
    Solution solution;
    int given_n = 5;
    int given_limit = 2;
    int expected_answer = 3;
    assert(solution.distributeCandies(given_n, given_limit) == expected_answer);

    given_n = 3;
    given_limit = 3;
    expected_answer = 10;
    assert(solution.distributeCandies(given_n, given_limit) == expected_answer);

    return 0;
}
