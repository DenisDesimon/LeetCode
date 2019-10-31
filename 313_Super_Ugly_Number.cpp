//#313 Super Ugly Number - https://leetcode.com/problems/super-ugly-number/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n < 0)
            return 0;
        vector<int> ugly_num(n);
        vector<int> mult(primes.size(), 0);
        ugly_num[0] = 1;
        for(int i = 1; i < n; i++)
        {
            int next_ugly = INT_MAX;
            for(int j = 0; j < (int)primes.size(); j++)
            {
                next_ugly = min(next_ugly, ugly_num[mult[j]] * primes[j]);
            }
            ugly_num[i] = next_ugly;
            for(int j = 0; j < (int)primes.size(); j++)
            {
                if(next_ugly == ugly_num[mult[j]] * primes[j])
                    mult[j]++;
            }
        }
        return ugly_num[n - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> given_primes = {2, 7, 13, 19};
    int given_n = 12;
    int expected_answer = 32;
    assert(solution.nthSuperUglyNumber(given_n, given_primes) == expected_answer);

    given_primes = {2, 3, 5};
    given_n = 10;
    expected_answer = 12;
    assert(solution.nthSuperUglyNumber(given_n, given_primes) == expected_answer);

    return 0;
}
