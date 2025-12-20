//#944 Delete Columns to Make Sorted - https://leetcode.com/problems/delete-columns-to-make-sorted/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int result = 0;
        for(int i = 0; i < (int)strs.front().size(); i++)
        {
            for(int j = 1; j < (int)strs.size(); j++)
            {
                if(strs[j][i] < strs[j - 1][i])
                {
                    result++;
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenStrs  = {"cba", "daf", "ghi"};
    int expectedAnswer = 1;
    assert(solution.minDeletionSize(givenStrs) == expectedAnswer);

    givenStrs = {"zyx", "wvu", "tsr"};
    expectedAnswer = 3;
    assert(solution.minDeletionSize(givenStrs) == expectedAnswer);

    return 0;
}
