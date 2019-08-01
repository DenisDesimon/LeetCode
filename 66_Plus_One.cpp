//#66 Plus One - https://leetcode.com/problems/plus-one/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int left = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            int num = digits[i] + left;
            digits[i] = num % 10;
            left = num / 10;
            if(i == 0 && left != 0)
                digits.insert(digits.begin(), left);
        }
        return digits;
    }
};

int main()
{
    Solution solution;
    vector<int> given_digits = {4, 3, 2, 1};
    vector<int> expected_anwer = {4, 3, 2, 2};
    assert(solution.plusOne(given_digits) == expected_anwer);

    given_digits = {9, 9, 9, 9};
    expected_anwer = {1, 0, 0, 0, 0};
    assert(solution.plusOne(given_digits) == expected_anwer);

    return 0;
}
