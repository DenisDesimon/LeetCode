//#3079 Find the Sum of Encrypted Integers - https://leetcode.com/problems/find-the-sum-of-encrypted-integers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int result = 0;
        for(int &num : nums)
        {
            int maxDigit = INT_MIN;
            int decimals = 0;
            int power = 1;
            while(num)
            {
                maxDigit = max(maxDigit, num %  10);
                num /= 10;
                decimals++;
            }
            while(decimals)
            {
                result += maxDigit * power;
                power *= 10;
                decimals--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3};
    int expected_answer = 6;
    assert(solution.sumOfEncryptedInt(given_nums) == expected_answer);

    given_nums = {11, 22, 33};
    expected_answer = 66;
    assert(solution.sumOfEncryptedInt(given_nums) == expected_answer);

    return 0;
}
