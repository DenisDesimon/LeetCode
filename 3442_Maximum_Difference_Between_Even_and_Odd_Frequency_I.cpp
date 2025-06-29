//#3442 Maximum Difference Between Even and Odd Frequency I - https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> alphabet(26);
        for(auto &letter : s)
            alphabet[letter - 'a']++;
        int maxOdd = 0, minEven = INT_MAX;
        for(auto &freq : alphabet)
        {
            if(freq != 0 && freq % 2 == 0)
                minEven = min(minEven, freq);
            else
                maxOdd = max(maxOdd, freq);
        }
        return maxOdd - minEven;
    }
};

int main()
{
    Solution solution;
    string given_s = "aaaaabbc";
    int expected_answer = 3;
    assert(solution.maxDifference(given_s) == expected_answer);

    given_s = "abcabcab";
    expected_answer = 1;
    assert(solution.maxDifference(given_s) == expected_answer);

    return 0;
}
