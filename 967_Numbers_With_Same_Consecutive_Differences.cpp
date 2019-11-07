//#967 Numbers With Same Consecutive Differences - https://leetcode.com/problems/numbers-with-same-consecutive-differences/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 1; i < N; i++)
        {
            vector<int> next;
            for(auto num : result)
            {
                int digit = num % 10;
                if(digit - K >= 0)
                    next.push_back(num * 10 + digit - K);
                if(K != 0 && digit + K < 10)
                    next.push_back(num * 10 + digit + K);
            }
            result = next;
        }
        if(N == 1)
            result.insert(result.begin(), 0);
        return result;
    }
};

int main()
{
    Solution solution;
    int given_N = 3;
    int given_K = 7;
    vector<int> expected_answer = {181, 292, 707, 818, 929};
    assert(solution.numsSameConsecDiff(given_N, given_K) == expected_answer);

    given_N = 2;
    given_K = 0;
    expected_answer = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    assert(solution.numsSameConsecDiff(given_N, given_K) == expected_answer);

    return 0;
}
