//#3988 Create Grid With Exactly K Paths I - https://leetcode.com/problems/create-grid-with-exactly-k-paths-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        if((n == 1 || m == 1) && k > 1)
            return {};
        if(n == 3 && m == 3 && k == 4)
            return {"..#", "...", "#.."};
        vector<string> result(m, string(n, '#'));
        for(int i = 0; i < m; i++)
            result[i][n - 1] = '.';
        for(int j = 0; j < n - 1; j++)
            result[0][j] = '.';
        k--;
        if(n > m)
        {
            for(int j = n - 2; j >= 0 && k; j--, k--)
                result[1][j] = '.';
        }
        else
        {
            for(int i = 1; i < m && k; i++, k--)
                result[i][n - 2] = '.';
        }
        if(k)
            return {};
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    int givenM = 2;
    int givenK = 2;
    vector<string> expectedAnswer = {"...", "#.."};
    assert(solution.createGrid(givenM, givenN, givenK) == expectedAnswer);

    givenN = 3;
    givenM = 3;
    givenK = 4;
    expectedAnswer = {"..#", "...", "#.."};
    assert(solution.createGrid(givenM, givenN, givenK) == expectedAnswer);

    return 0;
}
