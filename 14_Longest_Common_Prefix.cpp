//#14 Longest Common Prefix - https://leetcode.com/problems/longest-common-prefix/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string result = strs[0];
        for(int i = 1; i < (int)strs.size(); i++)
        {
            while(strs[i].compare(0, result.size(), result) != 0)
            {
                result.pop_back();
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> strs = {"dog", "racecar", "car"};
    string expected_answer = "";
    assert(solution.longestCommonPrefix(strs) == expected_answer);

    strs = {"flower", "flow", "flight"};
    expected_answer = "fl";
    assert(solution.longestCommonPrefix(strs) == expected_answer);

    return 0;
}
