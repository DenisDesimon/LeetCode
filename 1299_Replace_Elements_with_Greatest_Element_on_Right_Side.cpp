//#1299 Replace Elements with Greatest Element on Right Side - https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    int replace(vector<int>& arr, int i){
        if(i == (int)arr.size() - 1)
            return arr[i];
        int temp = arr[i];
        arr[i] = replace(arr, i + 1);
        return max(temp, arr[i]);
    }
public:
    vector<int> replaceElements(vector<int>& arr) {
        replace(arr, 0);
        arr.back() = -1;
        return arr;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {17, 18, 5, 4, 6, 1};
    vector<int> expected_answer = {18, 6, 6, 6, 1, -1};
    assert(solution.replaceElements(given_arr) == expected_answer);

    given_arr = {4, 5, 10, 1, 2};
    expected_answer = {10, 10, 2, 2, -1};
    assert(solution.replaceElements(given_arr) == expected_answer);

    return 0;
}
