//#2278 Percentage of Letter in String - https://leetcode.com/problems/percentage-of-letter-in-string/
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        return 100 * count(s.begin(), s.end(), letter) / s.size();
    }
};

int main()
{
    Solution solution;
    string given_s = "foobar";
    char given_letter = 'o';
    int expected_answer = 33;
    assert(solution.percentageLetter(given_s, given_letter) == expected_answer);

    given_s = "jjjj";
    given_letter = 'k';
    expected_answer = 0;
    assert(solution.percentageLetter(given_s, given_letter) == expected_answer);

    return 0;
}
