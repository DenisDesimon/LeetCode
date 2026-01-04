//#1390 Four Divisors - https://leetcode.com/problems/four-divisors/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for(auto &num : nums)
        {
            int divisor = 0;
            for(int i = 2; i * i <= num; i++)
            {
                if(num % i == 0)
                {
                    if(divisor == 0)
                        divisor = i;
                    else
                    {
                        divisor = 0;
                        break;
                    }
                }
            }
            if(divisor && divisor != num / divisor)
                result += num + 1 + divisor + num / divisor;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {21, 4, 7};
    int expectedAnswer = 32;
    assert(solution.sumFourDivisors(givenNums) == expectedAnswer);

    givenNums = {1, 2, 3, 4, 5};
    expectedAnswer = 0;
    assert(solution.sumFourDivisors(givenNums) == expectedAnswer);

    return 0;
}
