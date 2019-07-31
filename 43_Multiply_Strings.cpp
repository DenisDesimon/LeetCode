//43 Multiply Strings - https://leetcode.com/problems/multiply-strings/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cassert>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        vector<int> result(num1.size() + num2.size(), 0);
        for(int i = num1.size() - 1; i >= 0; i--)
        {
            for(int j = num2.size() - 1; j >= 0; j--)
            {
                result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                result[i + j] += result[i + j + 1] / 10;
                result[i + j + 1] %= 10;
            }
        }
        result = {find_if_not(result.begin(), result.end(), [](int a){return a == 0;}), result.end()};
        stringstream str_result;
        copy(result.begin(), result.end(), ostream_iterator<int>(str_result, ""));
        return str_result.str();
    }
};

int main()
{
    Solution solution;
    string given_num1 = "123";
    string given_num2 = "456";
    string expected_answer = "56088";
    assert(solution.multiply(given_num1, given_num2) == expected_answer);

    given_num1 = "3";
    given_num2 = "2";
    expected_answer = "6";
    assert(solution.multiply(given_num1, given_num2) == expected_answer);

    return 0;
}
