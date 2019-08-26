//#204 Count Primes - https://leetcode.com/problems/count-primes/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        int result = 0;
        for(long long i = 2; i * i < n; i++)
        {
            if(primes[i])
            {
                for(long long j = i * i; j < n; j += i)
                    primes[j] = false;
            }
        }
        for(int i = 2; i < n; i++)
        {
            if(primes[i])
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 12;
    int expected_answer = 5;
    assert(solution.countPrimes(given_n) == expected_answer);

    given_n = 25;
    expected_answer = 9;
    assert(solution.countPrimes(given_n) == expected_answer);

    return 0;
}
