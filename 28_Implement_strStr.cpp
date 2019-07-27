//#28 Implement strStr() - https://leetcode.com/problems/implement-strstr/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        int size_haystack = haystack.size(), size_needle = needle.size();
        for(int i = 0; i < (size_haystack - size_needle + 1); i++)
        {
            if(haystack[i] == needle[0] && haystack.compare(i, size_needle, needle) == 0)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string given_haystack = "hello";
    string given_needle = "ll";
    int expected_answer = 2;
    assert(solution.strStr(given_haystack, given_needle) == expected_answer);

    given_haystack = "aaaaa";
    given_needle = "bba";
    expected_answer = -1;
    assert(solution.strStr(given_haystack, given_needle) == expected_answer);

    return 0;
}
