//#338 Counting Bits - https://leetcode.com/problems/counting-bits/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for(int i = 1; i <= num; i++)
        {
            result[i] = 1 + result[i & (i - 1)];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_num = 5;
    vector<int> expected_answer = {0, 1, 1, 2, 1, 2};
    assert(solution.countBits(given_num) == expected_answer);

    given_num = 0;
    expected_answer = {0};
    assert(solution.countBits(given_num) == expected_answer);
    return 0;
}
