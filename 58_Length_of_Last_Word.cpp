//58 Length of Last Word - https://leetcode.com/problems/length-of-last-word/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int right = s.size() - 1;
        while(right >= 0 && s[right] == ' ')
            right--;
        int left = right;
        while(left >= 0 && s[left] != ' ')
            left--;
        return right - left;
    }
};

int main()
{
    Solution solutution;
    string given_s = "Hello World";
    int expected_answer = 5;
    assert(solutution.lengthOfLastWord(given_s) == expected_answer);

    given_s = "a ";
    expected_answer = 1;
    assert(solutution.lengthOfLastWord(given_s) == expected_answer);


    return 0;
}
