//#3234 Count the Number of Substrings With Dominant Ones - https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> prevZeroIdx(n + 1);
        prevZeroIdx[0] = -1;
        int result = 0;
        for(int i = 1; i < n; i++)
            prevZeroIdx[i + 1] = s[i - 1] == '0' ? i : prevZeroIdx[i];
        for(int right = 1; right <= n; right++)
        {
            int countZero = s[right - 1] == '0';
            int left = right;
            while(left > 0 && countZero * countZero <= right)
            {
                int countOnes = right - prevZeroIdx[left] - countZero;
                if(countZero * countZero <= countOnes)
                    result += min(left - prevZeroIdx[left], countOnes - countZero * countZero + 1);
                countZero++;
                left = prevZeroIdx[left];
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "00011";
    int expectedAnswer = 5;
    assert(solution.numberOfSubstrings(givenS) == expectedAnswer);

    givenS = "101101";
    expectedAnswer = 16;
    assert(solution.numberOfSubstrings(givenS) == expectedAnswer);

    return 0;
}
