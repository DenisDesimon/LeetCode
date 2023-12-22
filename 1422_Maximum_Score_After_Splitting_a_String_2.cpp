//#1422 Maximum Score After Splitting a String - https://leetcode.com/problems/maximum-score-after-splitting-a-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zeroes = 0, ones = 0;
        int result = INT_MIN;
        for(int i = 0; i < (int)s.size() - 1; i++)
        {
            if(s[i] == '1')
                ones++;
            else
                zeroes++;
            result = max(result, zeroes - ones);
        }
        if(s.back() == '1')
            ones++;
        return result + ones;
    }
};

int main()
{
    Solution solution;
    string given_s = "1111";
    int expected_answer = 3;
    assert(solution.maxScore(given_s) == expected_answer);

    given_s = "011101";
    expected_answer = 5;
    assert(solution.maxScore(given_s) == expected_answer);

    return 0;
}
