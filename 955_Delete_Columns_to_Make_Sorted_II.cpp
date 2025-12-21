//#955 Delete Columns to Make Sorted II - https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        unordered_set<int> deletedCols;
        for(int i = 1; i < (int)strs.size(); i++)
        {
            for(int j = 0; j < (int)strs.front().size(); j++)
            {
                if(deletedCols.count(j) || strs[i][j] == strs[i - 1][j])
                    continue;
                if(strs[i][j] < strs[i - 1][j])
                {
                    deletedCols.insert(j);
                    i = 0;
                }
                break;
            }
        }
        return deletedCols.size();
    }
};

int main()
{
    Solution solution;
    vector<string> givenStrs  = {"xc", "yb", "za"};
    int expectedAnswer = 0;
    assert(solution.minDeletionSize(givenStrs) == expectedAnswer);

    givenStrs = {"zyx", "wvu", "tsr"};
    expectedAnswer = 3;
    assert(solution.minDeletionSize(givenStrs) == expectedAnswer);

    return 0;
}
