//#960 Delete Columns to Make Sorted III - https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        vector<int> dp(strs.front().size(), 1);
        for(int i = 0; i < (int)strs.front().size(); i++)
        {
            for(int k = 0; k < i; k++)
            {
                for(int j = 0; j <= (int)strs.size(); j++)
                {
                    if(j == (int)strs.size())
                        dp[i] = max(dp[i], dp[k] + 1);
                    else if(strs[j][i] < strs[j][k])
                        break;
                }
            }
        }
        int maxLength = 0;
        for(auto &length : dp)
            maxLength = max(maxLength, length);
        return strs.front().size() - maxLength;
    }
};

int main()
{
    Solution solution;
    vector<string> givenStrs  = {"babca", "bbazb"};
    int expectedAnswer = 3;
    assert(solution.minDeletionSize(givenStrs) == expectedAnswer);

    givenStrs = {"ghi", "def", "abc"};
    expectedAnswer = 0;
    assert(solution.minDeletionSize(givenStrs) == expectedAnswer);

    return 0;
}
