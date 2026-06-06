//#3753 Total Waviness of Numbers in Range II - https://leetcode.com/problems/total-waviness-of-numbers-in-range-ii/
#include <iostream>
#include <cassert>
#include <string.h>
using namespace std;

class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        auto solve = [&](long long num) -> long long{
            if(num < 100)
                return 0;
            string s = to_string(num);
            int n = s.size();

            long long memoCount[16][10][10];
            long long memoSum[16][10][10];
            memset(memoCount, -1, sizeof(memoCount));
            memset(memoSum, -1, sizeof(memoSum));

            auto dfs = [&](this auto&& dfs, int pos, int prev, int cur, bool isLimit, bool isLeading) -> pair<long long, long long>{
                if(pos == n)
                    return {1, 0};

                if(!isLimit && !isLeading && prev >= 0 && cur >= 0){
                    if(memoCount[pos][prev][cur] != -1)
                        return {memoCount[pos][prev][cur], memoSum[pos][prev][cur]};
                }

                long long count = 0, sum = 0;

                int uperBound = isLimit ? s[pos] - '0' : 9;
                for(int digit = 0; digit <= uperBound; digit++)
                {
                    bool nextLeading = isLeading && digit == 0;

                    int nextPrev = cur;
                    int nextCur = nextLeading ? -1 : digit;

                    auto [subCount, subSum] = dfs(pos + 1, nextPrev, nextCur, isLimit && (digit == uperBound), nextLeading);
                    if(!nextLeading && prev >= 0 && cur >= 0)
                    {
                        if((prev < cur && cur > digit) || (prev > cur && cur < digit))
                            sum += subCount;
                    }
                    count += subCount;
                    sum += subSum;
                }
                if(!isLimit && !isLeading && prev >= 0 && cur >= 0)
                {
                    memoCount[pos][prev][cur] = count;
                    memoSum[pos][prev][cur] = sum;
                }
                return {count, sum};
            };

            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;

        };
        return solve(num2) - solve(num1 - 1);
    }
};


int main()
{
    Solution solution;
    int givenLeft = 120;
    int givenRight = 130;
    long long expectedAnswer = 3;
    assert(solution.totalWaviness(givenLeft, givenRight) == expectedAnswer);

    givenLeft = 4848;
    givenRight = 4848;
    expectedAnswer = 2;
    assert(solution.totalWaviness(givenLeft, givenRight) == expectedAnswer);

    return 0;
}
