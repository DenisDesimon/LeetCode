//#2231 Largest Number After Digit Swaps by Parity - https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string odd = "", even = "";
        vector<int> parity;
        int result = 0;
        while(num)
        {
            if(num % 10 % 2)
            {
                odd += '0' + num % 10;
                parity.push_back(1);
            }
            else
            {
                even += '0' + num % 10;
                parity.push_back(0);
            }
            num /= 10;
        }
        sort(odd.begin(), odd.end(), greater<>());
        sort(even.begin(), even.end(), greater<>());
        int oddIdx = 0, evenIdx = 0;
        reverse(parity.begin(), parity.end());
        for(int i = 0; i < (int)parity.size(); i++)
        {
            result *= 10;
            if(parity[i] == 1)
                result += odd[oddIdx++] - '0';
            else
                result += even[evenIdx++] - '0';
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenNum  = 1234;
    int expectedAnswer = 3412;
    assert(solution.largestInteger(givenNum) == expectedAnswer);

    givenNum  = 65875;
    expectedAnswer = 87655;
    assert(solution.largestInteger(givenNum) == expectedAnswer);

    return 0;
}
