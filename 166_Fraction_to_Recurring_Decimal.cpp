//#166 Fraction to Recurring Decimal - https://leetcode.com/problems/fraction-to-recurring-decimal/
#include <iostream>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        string result;
        if(numerator == 0)
            return "0";
        if((numerator < 0) ^ (denominator < 0))
            result += '-';
        numerator = abs(numerator), denominator = abs(denominator);
        result += to_string(numerator / denominator);
        unordered_map<long long, long long> hash;
        numerator %= denominator;
        if(numerator == 0)
            return result;
        result += '.';
        while(numerator)
        {
            if(hash.count(numerator))
            {
                result.insert(hash[numerator], "(");
                result += ')';
                break;
            }
            hash[numerator] = result.size();
            numerator *= 10;
            result += to_string(numerator / denominator);
            numerator %= denominator;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_num = 2, given_denom = 3;
    string expected_answer = "0.(6)";
    assert(solution.fractionToDecimal(given_num, given_denom) == expected_answer);

    given_num = 2, given_denom = 1;
    expected_answer = "2";
    assert(solution.fractionToDecimal(given_num, given_denom) == expected_answer);

    return 0;
}
