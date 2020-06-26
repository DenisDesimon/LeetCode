//#1035 Uncrossed Lines - https://leetcode.com/problems/uncrossed-lines/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
       vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
       for(int i = 0; i < (int)A.size(); i++)
       {
           for(int j = 0; j < (int)B.size(); j++)
           {
               if(A[i] == B[j])
                   dp[i + 1][j + 1] = dp[i][j] + 1;
               else
                   dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
           }
       }
       return dp.back().back();
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {3, 3, 3, 1};
    vector<int> given_B = {2, 2, 3, 3};
    int expected_answer = 2;
    assert(solution.maxUncrossedLines(given_A, given_B) == expected_answer);

    given_A = {2, 5, 1, 2, 5};
    given_B = {10, 5, 2, 1, 5, 2};
    expected_answer = 3;
    assert(solution.maxUncrossedLines(given_A, given_B) == expected_answer);

    return 0;
}
