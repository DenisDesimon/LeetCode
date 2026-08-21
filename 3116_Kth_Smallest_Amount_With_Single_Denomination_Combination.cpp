//#3116 Kth Smallest Amount With Single Denomination Combination - https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;


class Solution {
    long long gcd(long long a, long long b)
    {
        while(b)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int m = (1 << n);
        sort(coins.begin(), coins.end());
        vector<int> coinCount(m);
        vector<long long> lcm(m);
        long long l = k, r = 1ll * coins.front() * k + 1;
        for(int mask = 1; mask < m; mask++)
        {
            long long curLcm = 1;
            for(int i = 0; i < n; i++)
            {
                if(mask & (1 << i))
                {
                    long long tmp = curLcm / gcd(curLcm, coins[i]);
                    if(tmp <= r / coins[i])
                        curLcm = tmp * coins[i];
                    else
                    {
                        curLcm = r + 1;
                        break;
                    }
                    coinCount[mask]++;
                }
            }
            lcm[mask] = curLcm;
        }
        auto countCoins = [&](long long x){
            long long count = 0;
            for(int mask = 1; mask < m; mask++)
            {
                if(lcm[mask] > x)
                    continue;
                if(coinCount[mask] & 1)
                    count += x / lcm[mask];
                else
                    count -= x / lcm[mask];
            }
            return count;
        };
        while(l < r)
        {
            long long mid = (l + r) >> 1;
            if(countCoins(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main()
{
    Solution solution;
    vector<int> givenCoins = {3, 6, 9};
    int givenK = 3;
    long long expectedAnswer = 9;
    assert(solution.findKthSmallest(givenCoins, givenK) == expectedAnswer);

    givenCoins = {5, 2};
    givenK = 7;
    expectedAnswer = 12;
    assert(solution.findKthSmallest(givenCoins, givenK) == expectedAnswer);


    return 0;
}
