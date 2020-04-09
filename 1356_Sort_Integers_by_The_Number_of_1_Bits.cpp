//#1356 Sort Integers by The Number of 1 Bits - https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b){
        if(__builtin_popcount(a) == __builtin_popcount(b))
            return a < b;
        return __builtin_popcount(a) < __builtin_popcount(b);});
        return arr;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> expected_answer = {0, 1, 2, 4, 8, 3, 5, 6, 7};
    assert(solution.sortByBits(given_arr) == expected_answer);

    given_arr = {10, 100, 1000, 10000};
    expected_answer = {10, 100, 10000, 1000};
    assert(solution.sortByBits(given_arr) == expected_answer);

    return 0;
}
