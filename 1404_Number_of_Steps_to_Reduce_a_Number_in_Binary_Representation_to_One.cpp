//#1404 Number of Steps to Reduce a Number in Binary Representation to One - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int result = 0, carry = 0;
        for(int i = s.size() - 1; i > 0; i--)
        {
            if(s[i] - '0' + carry == 1)
            {
                carry = 1;
                result++;
            }
            result++;
        }
        return result + carry;
    }
};

int main()
{
    Solution solution;
    string given_s = "1101";
    int expected_answer = 6;
    assert(solution.numSteps(given_s) == expected_answer);

    given_s = "10";
    expected_answer = 1;
    assert(solution.numSteps(given_s) == expected_answer);

    return 0;
}
