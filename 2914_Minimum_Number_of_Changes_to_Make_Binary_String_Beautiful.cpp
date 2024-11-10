//#2914 Minimum Number of Changes to Make Binary String Beautiful - https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int result = 0;
        for(int i = 1; i < (int)s.size(); i += 2)
        {
            if(s[i] != s[i - 1])
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "1001";
    int expected_answer = 2;
    assert(solution.minChanges(given_s) == expected_answer);

    given_s = "0000";
    expected_answer = 0;
    assert(solution.minChanges(given_s) == expected_answer);

    return 0;
}
