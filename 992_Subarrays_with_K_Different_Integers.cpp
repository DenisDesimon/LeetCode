//#992 Subarrays with K Different Integers - https://leetcode.com/problems/subarrays-with-k-different-integers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<int> count(A.size() + 1);
        int unique = 0, result = 0;
        for(int i = 0, j = 0, pre = 0; i < (int)A.size(); i++)
        {
            if(count[A[i]]++ == 0)
                unique++;
            if(unique > K)
            {
                count[A[j++]]--;
                pre = 0;
                unique--;
            }
            while(count[A[j]] != 1)
            {
                pre++;
                count[A[j++]]--;
            }
            if(unique == K)
                result += 1 + pre;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_A = {1, 2, 1, 2, 3};
    int given_K = 2;
    int expected_answer = 7;
    assert(solution.subarraysWithKDistinct(given_A, given_K) == expected_answer);

    given_A = {1, 2, 1, 3, 4};
    given_K = 3;
    expected_answer = 3;
    assert(solution.subarraysWithKDistinct(given_A, given_K) == expected_answer);

    return 0;
}
