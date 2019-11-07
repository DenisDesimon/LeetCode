//#796 Rotate String - https://leetcode.com/problems/rotate-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};

int main()
{
    Solution solution;
    string given_A = "abcde";
    string given_B = "cdeab";
    bool expected_answer = true;
    assert(solution.rotateString(given_A, given_B) == expected_answer);

    given_A = "abcde";
    given_B = "abced";
    expected_answer = false;
    assert(solution.rotateString(given_A, given_B) == expected_answer);

    return 0;
}
