//#1461 Check If a String Contains All Binary Codes of Size K - https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
#include <iostream>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codes;
        for(int i = 0; i < (int)s.size() - k + 1; i++)
        {
            codes.insert(s.substr(i, k));
        }
        int target = 1;
        while(k--)
            target *= 2;
        return (int)codes.size() == target;
    }
};

int main()
{
    Solution solution;
    string givenS = "00110110";
    int givenK = 2;
    bool expectedAnswer = true;
    assert(solution.hasAllCodes(givenS, givenK) == expectedAnswer);

    givenS = "0110";
    givenK = 1;
    expectedAnswer = true;
    assert(solution.hasAllCodes(givenS, givenK) == expectedAnswer);

    return 0;
}
