//#1122 Relative Sort Array - https://leetcode.com/problems/relative-sort-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if(arr2.empty())
            return arr1;
       sort(arr1.begin(), arr1.end());
       vector<int> result;
       for(int i = 0; i < (int)arr2.size(); i++)
       {
           auto first_erase = upper_bound(arr1.begin(), arr1.end(), arr2[i] - 1);
           auto end_erase = upper_bound(arr1.begin(), arr1.end(), arr2[i]);
           result.insert(result.end(), first_erase, end_erase);
           arr1.erase(first_erase, end_erase);
       }
       result.insert(result.end(), arr1.begin(), arr1.end());
       return result;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1 = {28, 6, 22, 8, 44, 17};
    vector<int> arr2 = {22, 28, 8, 6};
    vector<int> expected_answer = {22, 28, 8, 6, 17, 44};
    assert(solution.relativeSortArray(arr1, arr2) == expected_answer);

    arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    arr2 = {2, 1, 4, 3, 9, 6};
    expected_answer = {2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19};
    assert(solution.relativeSortArray(arr1, arr2) == expected_answer);

    return 0;
}
