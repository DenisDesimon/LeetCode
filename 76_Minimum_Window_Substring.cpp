//#76 Minimum Window Substring - https://leetcode.com/problems/minimum-window-substring/
#include <iostream>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<int, char> t_filter;
        map<char, int> count_t;
        int n = s.size(), m = t.size();
        int count = 0;
        for(auto &ch : t)
            count_t[ch]++;
        string result = "";
        for(int i = 0; i < n; i++)
        {
            if(count_t.count(s[i]))
                t_filter[i] = s[i];
        }
        auto left = t_filter.begin();
        auto right = left;
        while(right != t_filter.end())
        {
             if(count_t[right->second]-- > 0)
                 count++;
             if(count < m)
             {
                 right++;
                 continue;
             }
             while(count == m)
             {
                 if(count_t[(left++)->second]++ >= 0)
                 {
                     left--;
                     count--;
                 }
             }
             if(result == "" || right->first - left->first + 1 < (int)result.size())
                  result = string(s.begin() + left->first, s.begin() + right->first + 1);
             left++, right++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "aaaaaaaaaaaabbbbbcdd", given_t = "abcdd";
    string expected_answer = "abbbbbcdd";
    assert(solution.minWindow(given_s, given_t) == expected_answer);

    given_s = "ADOBECODEBANC", given_t = "ABC";
    expected_answer = "BANC";
    assert(solution.minWindow(given_s, given_t) == expected_answer);

    return 0;
}
