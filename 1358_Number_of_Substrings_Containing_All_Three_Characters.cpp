//#1358 Number of Substrings Containing All Three Characters - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int result = 0;
        int n = s.size();
        vector<int> freq(3);
        for(int left = 0, right = 0; right < n; right++)
        {
            freq[s[right] - 'a']++;
            while(freq[0] && freq[1] && freq[2])
            {
                result += n - right;
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "abcabc";
    int expectedAnswer = 10;
    assert(solution.numberOfSubstrings(givenS) == expectedAnswer);

    givenS = "aaacb";
    expectedAnswer = 3;
    assert(solution.numberOfSubstrings(givenS) == expectedAnswer);

    return 0;
}
