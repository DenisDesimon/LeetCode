//#438 Find All Anagrams in a String - https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result, alpha(26, 0);
        int L = 0, R = 0, count = p.size();
        for(auto& ch : p)
            alpha[ch - 'a']++;
        while(R < (int)s.size())
        {
            if(alpha[s[R++] - 'a']-- > 0)
                count--;
            if(count == 0)
                result.push_back(L);
            if(R - L + 1 <= (int)p.size())
                continue;
            if(alpha[s[L++] - 'a']++ >= 0)
                count++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "cbaebabacd";
    string given_p = "abc";
    vector<int> expected_answer = {0, 6};
    assert(solution.findAnagrams(given_s, given_p) == expected_answer);

    given_s = "abab";
    given_p = "ab";
    expected_answer = {0, 1, 2};
    assert(solution.findAnagrams(given_s, given_p) == expected_answer);

    return 0;
}
