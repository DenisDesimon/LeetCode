//#1422 Maximum Score After Splitting a String - https://leetcode.com/problems/maximum-score-after-splitting-a-string/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int left_ones = s.front() == '1' ? 1 : 0, right_ones = 0;
        int result = 0;
        for(int i = 1; i < (int)s.size(); i++)
        {
            if(s[i] == '1')
                right_ones++;
        }
        for(int i = 1; i < (int)s.size(); i++)
        {
            result = max(result, i - left_ones + right_ones);
            if(s[i] == '1')
            {
                left_ones++;
                right_ones--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "011101";
    int expected_answer = 5;
    assert(solution.maxScore(given_s) == expected_answer);

    given_s = "1111";
    expected_answer = 3;
    assert(solution.maxScore(given_s) == expected_answer);

    return 0;
}
