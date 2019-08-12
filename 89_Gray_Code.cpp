//#89 Gray Code - https://leetcode.com/problems/gray-code/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for(int i = 0; i < (1 << n); i++)
            result.push_back(i ^ (i >> 1));
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 2;
    vector<int> expected_answer = {0, 1, 3, 2};
    assert(solution.grayCode(given_n) == expected_answer);

    given_n = 3;
    expected_answer = {0, 1, 3, 2, 6, 7, 5, 4};
    assert(solution.grayCode(given_n) == expected_answer);

    return 0;
}
