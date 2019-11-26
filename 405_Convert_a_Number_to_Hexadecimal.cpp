//#405 Convert a Number to Hexadecimal - https://leetcode.com/problems/convert-a-number-to-hexadecimal/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string result;
        for(unsigned int n = num; n; n >>= 4)
        {
            int cur = n % 16;
            if(cur < 10)
                result.insert(result.begin(), '0' + cur);
            else
                result.insert(result.begin(), 'a' + cur - 10);
        }
        return result.empty() ? "0" : result;
    }
};

int main()
{
    Solution solution;
    int given_num = -1;
    string expected_answer = "ffffffff";
    assert(solution.toHex(given_num) == expected_answer);

    given_num = 26;
    expected_answer = "1a";
    assert(solution.toHex(given_num) == expected_answer);

    return 0;
}
