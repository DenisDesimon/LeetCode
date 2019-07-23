//#1128 Number of Equivalent Domino Pairs - https://leetcode.com/problems/number-of-equivalent-domino-pairs/
#include <iostream>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> hash;
        int result = 0;
        for(auto domino : dominoes)
        {
            result += hash[{min(domino[0], domino[1]), max(domino[0], domino[1])}]++;
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> given_dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    int expected_answer = 1;
    assert(solution.numEquivDominoPairs(given_dominoes) == expected_answer);

    given_dominoes = {{1, 1}, {2, 2}, {1, 1}, {1, 2}, {1, 2}, {1, 1}};
    expected_answer = 4;
    assert(solution.numEquivDominoPairs(given_dominoes) == expected_answer);

    return 0;
}
