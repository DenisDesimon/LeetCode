//#2200 Find All K-Distant Indices in an Array - https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int left, right = 0;
        for(int i = 0; i < (int)nums.size(); i++)
        {
            if(nums[i] == key)
            {
                left = max(right, i - k);
                right = min((int)nums.size(), i + k + 1);
                while(left < right)
                    result.push_back(left++);
            }
        }
        return vector(result.begin(), result.end());
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 4, 9, 1, 3, 9, 5};
    int given_key = 9;
    int given_k = 1;
    vector<int> expected_answer = {1, 2, 3, 4, 5, 6};
    assert(solution.findKDistantIndices(given_nums, given_key, given_k) == expected_answer);

    given_nums = {2, 2, 2, 2, 2};
    given_key = 2;
    given_k = 2;
    expected_answer = {0, 1, 2, 3, 4};
    assert(solution.findKDistantIndices(given_nums, given_key, given_k) == expected_answer);

    return 0;
}
