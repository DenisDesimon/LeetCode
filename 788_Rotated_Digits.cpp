//#788 Rotated Digits - https://leetcode.com/problems/rotated-digits/
#include <iostream>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int result = 0;
        for(int i = 1; i <= N; i++)
        {
            bool has_changed = false;
            int num = i;
            while(num)
            {
                int digit = num % 10;
                if(digit == 2 || digit == 5 || digit == 6 || digit == 9)
                    has_changed = true;
                else if(digit == 3 || digit == 4 || digit == 7)
                {
                    has_changed = false;
                    break;
                }
                num /= 10;
            }
            if(has_changed)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_N = 10;
    int expected_answer = 4;
    assert(solution.rotatedDigits(given_N) == expected_answer);

    given_N = 1;
    expected_answer = 0;
    assert(solution.rotatedDigits(given_N) == expected_answer);

    return 0;
}
