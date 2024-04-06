//#3090 Maximum Length Substring With Two Occurrences - https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int alphabet[26] = {}, result = 0;
        for(int right = 0, left = 0; right < (int)s.size(); right++){
            if(++alphabet[s[right] - 'a'] > 2)
            {
                while(alphabet[s[right] - 'a'] > 2)
                    --alphabet[s[left++] - 'a'];
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "bcbbbcba";
    int expected_answer = 4;
    assert(solution.maximumLengthSubstring(given_s) == expected_answer);

    given_s = "aaaa";
    expected_answer = 2;
    assert(solution.maximumLengthSubstring(given_s) == expected_answer);

    return 0;
}
