//#3499 Maximize Active Section with Trade I - https://leetcode.com/problems/maximize-active-section-with-trade-i/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int countOnes = 0;
        int countZeroes = 0, longestSection = 0, prevCount = INT_MIN;
        for(int right = 0; right < n; )
        {
            int left = right;
            while(right < n && s[left] == s[right])
                right++;
            if(s[left] == '0')
            {
                countZeroes = right - left;
                longestSection = max(countZeroes + prevCount, longestSection);
                prevCount = countZeroes;
            }
            else
                countOnes += right - left;
        }
        return countOnes + longestSection;
    }
};

int main()
{
    Solution solution;
    string givenS = "1000100";
    int expectedAnswer = 7;
    assert(solution.maxActiveSectionsAfterTrade(givenS) == expectedAnswer);

    givenS = "0100";
    expectedAnswer = 4;
    assert(solution.maxActiveSectionsAfterTrade(givenS) == expectedAnswer);

    return 0;
}
