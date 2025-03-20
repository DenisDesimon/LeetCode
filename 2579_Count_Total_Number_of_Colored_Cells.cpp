//#2579 Count Total Number of Colored Cells - https://leetcode.com/problems/count-total-number-of-colored-cells/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return 2 * (long long) n * ((long long)n - 1) + 1;
    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    int expected_answer = 13;
    assert(solution.coloredCells(given_n) == expected_answer);

    given_n = 4;
    expected_answer = 25;
    assert(solution.coloredCells(given_n) == expected_answer);

    return 0;
}
