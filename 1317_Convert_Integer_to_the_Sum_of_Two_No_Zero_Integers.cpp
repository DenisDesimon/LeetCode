//#1317 Convert Integer to the Sum of Two No-Zero Integers  - https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    bool isNoZero(int num){
        while(num){
            if(num % 10 == 0)
                return false;
            num /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        int left = 1;
        while(left <= n / 2)
        {
            if(isNoZero(left) && isNoZero(n - left))
                return {left, n - left};
            left++;
        }
        return {-1, -1};
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    vector<int> expectedAnswer = {1, 1};
    assert(solution.getNoZeroIntegers(givenN) == expectedAnswer);

    givenN = 11;
    expectedAnswer = {2, 9};
    assert(solution.getNoZeroIntegers(givenN) == expectedAnswer);

    return 0;
}
