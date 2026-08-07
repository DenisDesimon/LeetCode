//#3348 Smallest Divisible Digit Product II - https://leetcode.com/problems/smallest-divisible-digit-product-ii/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
    int gcd(long long a, long long b)
    {
        while(b)
        {
            a %= b;
            swap(a, b);
        }
        return a;
    }
public:
    string smallestNumber(string num, long long t) {
        long long dividers = t;
        for(int i = 2; i <= 9; i++)
        {
            while(dividers % i == 0)
                dividers /= i;
        }
        if(dividers > 1)
            return "-1";
        int n = num.size();
        vector<long long> remainders(n + 1);
        remainders[0] = t;
        int pos = n - 1;
        for(int i = 0; i < n; i++)
        {
            if(num[i] == '0')
            {
                pos = i;
                break;
            }
            remainders[i + 1] = remainders[i] / gcd(remainders[i], num[i] - '0');
        }
        if(remainders[n] == 1)
            return num;

        for(int i = pos; i >= 0; i--)
        {
            while(++num[i] <= '9')
            {
                long long curT = remainders[i] / gcd(remainders[i], num[i] - '0');
                int curDigit = 9;
                for(int j = n - 1; j > i; j--)
                {
                    while(curT % curDigit)
                        curDigit--;
                    num[j] = '0' + curDigit;
                    curT /= curDigit;
                }
                if(curT == 1)
                    return num;
            }
        }

        string result;
        for(int i = 9; i > 1; i--)
        {
            while(t % i == 0)
            {
                result += '0' + i;
                t /= i;
            }
        }
        result += string(max(0, n + 1 - (int)result.size()), '1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution solution;
    string givenNum = "1234";
    long long givenK = 256;
    string expectedAnswer = "1488";
    assert(solution.smallestNumber(givenNum, givenK) == expectedAnswer);

    givenNum = "12355";
    givenK = 50;
    expectedAnswer = "12355";
    assert(solution.smallestNumber(givenNum, givenK) == expectedAnswer);

    return 0;
}
