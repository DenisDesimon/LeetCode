//#395 Longest Substring with At Least K Repeating Characters - https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int size_s = s.size();
        if(size_s < k)
            return 0;
        int alphobet[26] = {0};
        int min_count = INT_MAX;
        char delim = 'd';
        int result = 0;
        for(auto& ch : s)
            alphobet[ch - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            if(alphobet[i] != 0 && min_count > alphobet[i])
            {
                min_count = alphobet[i];
                delim = 'a' + i;
            }
        }
        if(min_count >= k)
            return size_s;
        stringstream ss(s);
        string part;
        while(getline(ss, part, delim))
            result = max(result, longestSubstring(part, k));
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "aaabb";
    int given_k = 3;
    int expected_answer = 3;
    assert(solution.longestSubstring(given_s, given_k) == expected_answer);

    given_s = "ababbc";
    given_k = 2;
    expected_answer = 5;
    assert(solution.longestSubstring(given_s, given_k) == expected_answer);

    return 0;
}
