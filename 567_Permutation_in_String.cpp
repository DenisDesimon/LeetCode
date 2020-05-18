//#567 Permutation in String - https://leetcode.com/problems/permutation-in-string/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> alpha(26, 0);
        for(auto& ch : s1)
            alpha[ch - 'a']++;
        int R = 0, L = 0, count = s1.size();
        while(R < (int)s2.size())
        {
            if(alpha[s2[R++] - 'a']-- > 0)
                count--;
            if(count == 0)
                return true;
            if(R - L + 1 <= (int)s1.size())
                continue;
            if(alpha[s2[L++] - 'a']++ >= 0)
                count++;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string given_s1 = "ab";
    string given_s2 = "eidbaooo";
    bool expected_answer = true;
    assert(solution.checkInclusion(given_s1, given_s2) == expected_answer);

    given_s1 = "ab";
    given_s2 = "eidboaoo";
    expected_answer = false;
    assert(solution.checkInclusion(given_s1, given_s2) == expected_answer);

    return 0;
}
