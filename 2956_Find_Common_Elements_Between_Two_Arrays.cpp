//#2956 Find Common Elements Between Two Arrays - https://leetcode.com/problems/find-common-elements-between-two-arrays/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(2, 0);
        unordered_map<int, int> hash;
        for(auto &num : nums1)
            hash[num]++;
        for(auto &num : nums2)
        {
            if(hash.count(num))
            {
                result[0] += hash[num];
                hash[num] = 0;
                result[1]++;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums1 = {4, 3, 2, 3, 1};
    vector<int> given_nums2 = {2, 2, 5, 2, 3, 6};
    vector<int> expected_answer = {3, 4};
    assert(solution.findIntersectionValues(given_nums1, given_nums2) == expected_answer);

    given_nums1 = {3, 4, 2, 3};
    given_nums2 = {1, 5};
    expected_answer = {0, 0};
    assert(solution.findIntersectionValues(given_nums1, given_nums2) == expected_answer);

    return 0;
}
