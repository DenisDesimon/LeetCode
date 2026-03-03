//#1545 Find Kth Bit in Nth Binary String - https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    char getBit(vector<int> &size, int level, int cur)
    {
        if(level == 0)
            return '0';
        int half = size[level] / 2;
        if(cur == half)
            return '1';
        if(cur < half)
            return getBit(size, level - 1, cur);
        return '0' + !(getBit(size, level - 1, 2 * half - cur) - '0');
    }
public:
    char findKthBit(int n, int k) {
        vector<int> size(n, 1);
        for(int i = 1; i < n; i++)
        {
            size[i] = size[i - 1] * 2 + 1;
        }
        return getBit(size, n - 1, k - 1);
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    int givenK = 1;
    char expectedAnswer = '0';
    assert(solution.findKthBit(givenN, givenK) == expectedAnswer);

    givenN = 4;
    givenK = 11;
    expectedAnswer = '1';
    assert(solution.findKthBit(givenN, givenK) == expectedAnswer);

    return 0;
}
