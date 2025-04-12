//#3272 Find the Count of Good Integers - https://leetcode.com/problems/find-the-count-of-good-integers/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> palindromes;
        int isOdd = n & 1;
        int start = pow(10, (n - 1) / 2);
        for(int num = start; num < start * 10; num++)
        {
            string palindrom = to_string(num);
            palindrom += string(palindrom.rbegin() + isOdd, palindrom.rend());
            if(stoll(palindrom) % k == 0){
                sort(palindrom.begin(), palindrom.end());
                palindromes.insert(palindrom);
            }
        }
        vector<int> factorial(n + 1, 1);
        for(int i = 2; i <= n; i++)
            factorial[i] = factorial[i - 1] * i;
        long long result = 0;
        for(auto &palindrom : palindromes)
        {
            vector<int> countDigits(10, 0);
            for(auto &digit : palindrom)
                countDigits[digit - '0']++;
            int combination = factorial[(int)palindrom.size()];
            for(auto &digit : countDigits)
                combination /= factorial[digit];
            result += combination;
            if(countDigits[0])
            {
                int combinationZero = factorial[(int)palindrom.size() - 1];
                countDigits[0]--;
                for(auto &digit : countDigits)
                    combinationZero /= factorial[digit];
                result -= combinationZero;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 1;
    int given_k = 4;
    int expected_answer = 2;
    assert(solution.countGoodIntegers(given_n, given_k) == expected_answer);

    given_n = 5;
    given_k = 6;
    expected_answer = 2468;
    assert(solution.countGoodIntegers(given_n, given_k) == expected_answer);

    return 0;
}
