//#1524 Number of Sub-arrays With Odd Sum  - https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int prefix = 0;
        long long countOdd = 0, countEven = 0;
        for(int i = 0; i < (int)arr.size(); i++)
        {
            prefix += arr[i];
            if(prefix % 2)
                countOdd++;
            else
                countEven++;
        }
        return ((countEven * countOdd) % MOD + countOdd) % MOD;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr = {1, 3, 5};
    int expectedAnswer = 4;
    assert(solution.numOfSubarrays(givenArr) == expectedAnswer);

    givenArr = {1, 2, 3, 4, 5, 6, 7};
    expectedAnswer = 16;
    assert(solution.numOfSubarrays(givenArr) == expectedAnswer);

    return 0;
}
