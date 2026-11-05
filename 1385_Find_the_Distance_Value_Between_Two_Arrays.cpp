//#1385 Find the Distance Value Between Two Arrays - https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int result = 0;
        int n = arr2.size();
        for(auto &num : arr1)
        {
            int idx = upper_bound(arr2.begin(), arr2.end(), num) - arr2.begin();
            if((idx == n ||  arr2[idx] - num > d) && (idx == 0 || num - arr2[idx - 1] > d))
                    result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr1 = {4, 5, 8};
    vector<int> givenArr2 = {10, 9, 1, 8};
    int givenD = 2;
    int expectedAnswer = 2;
    assert(solution.findTheDistanceValue(givenArr1, givenArr2, givenD) == expectedAnswer);

    givenArr1 = {2, 1, 100, 3};
    givenArr2 = {-5, -2, 10, -3, 7};
    givenD = 6;
    expectedAnswer = 1;
    assert(solution.findTheDistanceValue(givenArr1, givenArr2, givenD) == expectedAnswer);


    return 0;
}
