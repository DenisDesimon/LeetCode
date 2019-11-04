//#1221 Split a String in Balanced Strings - https://leetcode.com/problems/split-a-string-in-balanced-strings/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0, count = 0;
        for(auto ch : s)
        {
            ch == 'R' ? count++ : count--;
            if(count == 0)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "RLRRLLRLRL";
    int expected_answer = 4;
    assert(solution.balancedStringSplit(given_s) == expected_answer);

    given_s = "LLLLRRRR";
    expected_answer = 1;
    assert(solution.balancedStringSplit(given_s) == expected_answer);

    return 0;
}
