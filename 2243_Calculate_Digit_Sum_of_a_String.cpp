//#2243 Calculate Digit Sum of a String - https://leetcode.com/problems/calculate-digit-sum-of-a-string/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while((int)s.size() > k)
        {
            string temp;
            for(int i = 0; i < (int)s.size(); i += k)
            {
                int sum = 0;
                for(int j = i; j < i + k && j < (int)s.size(); j++)
                    sum += s[j] - '0';
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};

int main()
{
    Solution solution;
    string given_s = "11111222223";
    int given_k = 3;
    string expected_answer = "135";
    assert(solution.digitSum(given_s, given_k) == expected_answer);

    given_s = "00000000";
    given_k = 3;
    expected_answer = "000";
    assert(solution.digitSum(given_s, given_k) == expected_answer);

    return 0;
}
