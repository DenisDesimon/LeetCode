//#2999 Count the Number of Powerful Integers - https://leetcode.com/problems/count-the-number-of-powerful-integers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    long long dfs(int curDigit, bool ifSameAsLowest, bool ifSameAsHighest, string &lowestValue, string &highestValue, vector<long long> &memo, int &prefixLength, int &limit, string &s){\
        if(curDigit == (int)highestValue.size())
            return 1;
        if(!ifSameAsLowest && !ifSameAsHighest && memo[curDigit] != -1)
            return memo[curDigit];
        int lowestDigit = ifSameAsLowest ? lowestValue[curDigit] - '0' : 0;
        int highestDigit = ifSameAsHighest ? highestValue[curDigit] - '0' : 9;
        long long result = 0;
        if(curDigit < prefixLength)
        {
            for(int i = lowestDigit; i <= min(limit, highestDigit); i++)
                result += dfs(curDigit + 1, ifSameAsLowest && i == lowestDigit, ifSameAsHighest && i == highestDigit, lowestValue, highestValue, memo, prefixLength, limit, s);
        }
        else{
            int digit = s[curDigit - prefixLength] - '0';
            if(digit >= lowestDigit && digit <= min(limit, highestDigit))
                result = dfs(curDigit + 1, ifSameAsLowest && digit == lowestDigit, ifSameAsHighest && digit == highestDigit, lowestValue, highestValue, memo, prefixLength, limit, s);
        }
        if(!ifSameAsHighest && !ifSameAsLowest)
            memo[curDigit] = result;
        return result;

    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string lowestValue = to_string(start);
        string highestValue = to_string(finish);
        int prefixLength = highestValue.size() - s.size();
        lowestValue = string(highestValue.size() - lowestValue.size(), '0') + lowestValue;
        vector<long long> memo(highestValue.size(), -1);
        return dfs(0, true, true, lowestValue, highestValue, memo, prefixLength, limit, s);
    }
};

int main()
{
    Solution solution;
    long long given_start = 15;
    long long given_finish = 215;
    int given_limit = 6;
    string given_s = "10";
    long long expected_answer = 2;
    assert(solution.numberOfPowerfulInt(given_start, given_finish, given_limit, given_s) == expected_answer);

    given_start = 1;
    given_finish = 6000;
    given_limit = 4;
    given_s = "124";
    expected_answer = 5;
    assert(solution.numberOfPowerfulInt(given_start, given_finish, given_limit, given_s) == expected_answer);

    return 0;
}
