//#3850 Count Sequences to K - https://leetcode.com/problems/count-sequences-to-k/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        unordered_map<string, int> cur;
        cur["1#1"] = 1;
        for(auto &num : nums)
        {
            unordered_map<string, int> next;
            for(auto &[fraction, count] : cur)
            {
                int idx = fraction.find('#');
                long long p = stol(fraction.substr(0, idx));
                long long q = stol(fraction.substr(idx + 1));
                next[to_string(p) + '#' + to_string(q)] += count;
                {
                    long long nextP = p * num;
                    long long nextQ = q;
                    int d = gcd(nextP, nextQ);
                    nextP /= d;
                    nextQ /= d;
                    next[to_string(nextP) + '#' + to_string(nextQ)] += count;
                }
                {
                    long long nextP = p;
                    long long nextQ = q * num;
                    int d = gcd(nextP, nextQ);
                    nextP /= d;
                    nextQ /= d;
                    next[to_string(nextP) + '#' + to_string(nextQ)] += count;
                }
            }
            cur.swap(next);
        }
        return cur[to_string(k) + "#1"];
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, 2, 1, 6, 3, 3, 6, 5, 4, 4, 2, 1 ,6, 6};
    int givenK = 1620;
    int expectedAnswer = 4320;
    assert(solution.countSequences(givenNums, givenK) == expectedAnswer);

    givenNums = {2, 3, 2};
    givenK = 6;
    expectedAnswer = 2;
    assert(solution.countSequences(givenNums, givenK) == expectedAnswer);

    return 0;
}
