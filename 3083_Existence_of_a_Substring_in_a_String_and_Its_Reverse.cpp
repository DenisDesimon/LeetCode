//#3083 Existence of a Substring in a String and Its Reverse - https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/
#include <iostream>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> hash;
        for(int i = 1; i < (int)s.size(); i++)
        {
            hash.insert(string(1, s[i]) + string(1, s[i - 1]));
        }
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(hash.count(string(1, s[i - 1]) + string(1, s[i])))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string given_s = "leetcode";
    bool expected_answer = true;
    assert(solution.isSubstringPresent(given_s) == expected_answer);

    given_s = "abcd";
    expected_answer = false;
    assert(solution.isSubstringPresent(given_s) == expected_answer);

    return 0;
}
