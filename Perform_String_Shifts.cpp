//#Perform String Shifts - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/529/week-2/3299
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/* You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:
    direction can be 0 (for left shift) or 1 (for right shift).
    amount is the amount by which string s is to be shifted.
    A left shift by 1 means remove the first character of s and append it to the end.
    Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.
*/

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int shifts = 0;
        bool sign;
        for(auto& num : shift)
            shifts += num[0] == 0 ? -num[1] : num[1];
        sign = shifts < 0;
        shifts = abs(shifts) % s.size();
        shifts = sign ? s.size() - shifts : shifts;
        reverse(s.begin(), s.end());
        reverse(s.begin() + shifts, s.end());
        reverse(s.begin(), s.begin() + shifts);
        return s;
    }
};

int main()
{
    Solution solution;
    string given_s = "wpdhhcj";
    vector<vector<int>> given_shift = {{0, 7}, {1, 7}, {1, 0}, {1, 3}, {0, 3}, {0, 6}, {1, 2}};
    string expected_answer = "hcjwpdh";
    assert(solution.stringShift(given_s, given_shift) == expected_answer);

    given_s = "abc";
    given_shift = {{0, 1}, {1, 2}};
    expected_answer = "cab";
    assert(solution.stringShift(given_s, given_shift) == expected_answer);

    return 0;
}
