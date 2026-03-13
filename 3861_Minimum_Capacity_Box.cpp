//#3861 Minimum Capacity Box - https://leetcode.com/problems/minimum-capacity-box/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        capacity.push_back(INT_MAX);
        int idx = n;
        for(int i = 0; i < n; i++)
        {
            if(capacity[i] >= itemSize && capacity[idx] > capacity[i])
                idx = i;
        }
        return idx == n ? -1 : idx;
    }
};

int main()
{
    Solution solution;
    vector<int> givenCapacity = {1, 5, 3, 7};
    int givenItemSize = 3;
    int expectedAnswer = 2;
    assert(solution.minimumIndex(givenCapacity, givenItemSize) == expectedAnswer);

    givenCapacity = {3, 5, 4, 3};
    givenItemSize = 2;
    expectedAnswer = 0;
    assert(solution.minimumIndex(givenCapacity, givenItemSize) == expectedAnswer);

    return 0;
}
