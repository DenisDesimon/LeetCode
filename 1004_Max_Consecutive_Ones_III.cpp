//#1004 Max Consecutive Ones III - https://leetcode.com/problems/max-consecutive-ones-iii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int left = 0, swap = 0, result = 0;
        for(int i = 0; i < (int)A.size(); i++)
        {
            swap +=1 - A[i];
            while(swap > K)
            {
                if(A[left++] == 0)
                    swap--;
            }
            result = max(result, i - left + 1);
        }
        return result;

    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int given_K = 3;
    int  expected_answer = 10;
    assert(solution.longestOnes(given_nums, given_K) == expected_answer);


    given_nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
        given_K = 2;
    expected_answer = 6;
    assert(solution.longestOnes(given_nums, given_K) == expected_answer);

    return 0;
}
