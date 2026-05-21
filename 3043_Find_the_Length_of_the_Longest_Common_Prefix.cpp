//#3043 Find the Length of the Longest Common Prefix - https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefix;
        int result = 0;
        for(auto &num : arr1)
        {
            while(num)
            {
                prefix.insert(num);
                num /= 10;
            }
        }
        for(auto &num : arr2)
        {
            while(num)
            {
                if(prefix.count(num))
                {
                    result = max(result, num);
                    break;
                }
                else if(num < result)
                    break;
                num /= 10;
            }
        }
        int size = 0;
        while(result)
        {
            size++;
            result /= 10;
        }
        return size;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr1  = {1, 10, 100};
    vector<int> givenArr2  = {1000};
    int expectedAnswer = 3;
    assert(solution.longestCommonPrefix(givenArr1, givenArr2) == expectedAnswer);

    givenArr1  = {1, 2, 3};
    givenArr2  = {4, 4, 4, 4};
    expectedAnswer = 0;
    assert(solution.longestCommonPrefix(givenArr1, givenArr2) == expectedAnswer);

    return 0;
}
