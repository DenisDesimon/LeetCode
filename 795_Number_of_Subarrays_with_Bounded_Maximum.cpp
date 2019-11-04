//#795 Number of Subarrays with Bounded Maximum - https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result = 0, count_bounded = 0, count_lower_bound = 0;
        for(int i = 0; i < (int)A.size(); i++)
        {
            if(A[i] >= L && A[i] <= R)
            {
                count_bounded += count_lower_bound;
                count_lower_bound = 0;
                if(count_bounded++)
                    result += count_bounded - 1;
                result++;
            }
            else if(A[i] < L)
            {
                if(count_bounded)
                    result += count_bounded;
                count_lower_bound++;
            }
            else
            {
                count_bounded = 0;
                count_lower_bound = 0;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {2, 1, 4, 3};
    int given_L = 2;
    int given_R = 3;
    int expected_answer = 3;
    assert(solution.numSubarrayBoundedMax(given_A, given_L, given_R) == expected_answer);

    given_A = {73, 55, 36, 5, 55, 14, 9, 7, 72, 52};
    given_L = 32;
    given_R = 69;
    expected_answer = 22;
    assert(solution.numSubarrayBoundedMax(given_A, given_L, given_R) == expected_answer);

    return 0;
}
