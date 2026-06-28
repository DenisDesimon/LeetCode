//#3955 Valid Binary Strings With Cost Limit - https://leetcode.com/problems/valid-binary-strings-with-cost-limit/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    void backtrack(vector<string> &result, string cur, int pos, int count, bool isPrevOne, int n, int k){
        if(pos == n)
        {
            result.push_back(cur);
            return;
        }
        backtrack(result, cur + "0", pos + 1, count, false, n, k);
        if(!isPrevOne && count + pos <= k)
            backtrack(result, cur + "1", pos + 1, count + pos, true, n, k);
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> result;
        backtrack(result, "", 0, 0, false, n, k);
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    int givenK = 1;
    vector<string> expectedAnswer = {"000", "010", "100"};
    assert(solution.generateValidStrings(givenN, givenK) == expectedAnswer);

    givenN = 1;
    givenK = 0;
    expectedAnswer = {"0", "1"};
    assert(solution.generateValidStrings(givenN, givenK) == expectedAnswer);

    return 0;
}
