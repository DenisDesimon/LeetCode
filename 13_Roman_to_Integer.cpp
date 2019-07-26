//#13 Roman to Integer - https://leetcode.com/problems/roman-to-integer/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> decima =
        {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0, prev = INT_MIN;
        for(int i = (int)s.size() - 1; i >= 0; i--)
        {
            int cur_num = decima[s[i]];
            if(prev > cur_num)
                result -= cur_num;
            else
                result += cur_num;
            prev = cur_num;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "MCMXCIV";
    int expected_answer = 1994;
    assert(solution.romanToInt(given_s) == expected_answer);

    given_s = "LVIII";
    expected_answer = 58;
    assert(solution.romanToInt(given_s) == expected_answer);

    return 0;
}
