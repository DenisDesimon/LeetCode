//#344 Reverse String - https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

int main()
{
    Solution solution;
    vector<char> given_s = {'h', 'e', 'l', 'l', 'o'};
    vector<char> expected_answer = {'o', 'l', 'l', 'e', 'h'};
    solution.reverseString(given_s);
    assert(given_s == expected_answer);

    return 0;
}
