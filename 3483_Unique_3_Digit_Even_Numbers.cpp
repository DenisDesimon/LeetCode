//#3483 Unique 3-Digit Even Numbers - https://leetcode.com/problems/unique-3-digit-even-numbers/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count[10] = {0};
        int result = 0;
        for(auto &digit : digits)
            count[digit]++;
        for(int i = 1; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < 9; k += 2)
                {
                    result += count[i] && count[j] > (i == j) && count[k] > (i == k) + (j == k);
                }
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> digits = {1, 2, 3, 4};
    int expectedAnswer = 12;
    assert(solution.totalNumbers(digits) == expectedAnswer);

    digits = {1, 3, 5};
    expectedAnswer = 0;
    assert(solution.totalNumbers(digits) == expectedAnswer);


    return 0;
}
