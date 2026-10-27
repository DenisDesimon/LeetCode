//#3963 Create Grid With Exactly One Path - https://leetcode.com/problems/create-grid-with-exactly-one-path/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m, string(n, '#'));
        for(int j = 0; j < n; j++)
            result[0][j] = '.';
        for(int i = 0; i < m; i++)
            result[i][n - 1] = '.';
        return result;
    }
};

int main()
{
    Solution solution;
    int givenM = 2;
    int givenN = 3;
    vector<string> expectedAnswer = {"...", "##."};
    assert(solution.createGrid(givenM, givenN) == expectedAnswer);

    givenM = 3;
    givenN = 3;
    expectedAnswer = {"...", "##.", "##."};
    assert(solution.createGrid(givenM, givenN) == expectedAnswer);

    return 0;
}
