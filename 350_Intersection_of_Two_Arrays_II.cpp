//#350 Intersection of Two Arrays II - hhttps://leetcode.com/problems/intersection-of-two-arrays-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> result;
        for(auto num : nums1)
        {
            hash[num]++;
        }
        for(auto num : nums2)
        {
            if(hash[num])
            {
                result.push_back(num);
                hash[num]--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums1 = {1, 2, 2, 1};
    vector<int> given_nums2 = {2, 2};
    vector<int> expected_answer = {2, 2};
    assert(solution.intersect(given_nums1, given_nums2) == expected_answer);

    given_nums1 = {4, 9, 5};
    given_nums2 = {9, 4, 9, 8, 4};
    expected_answer = {9, 4};
    assert(solution.intersect(given_nums1, given_nums2) == expected_answer);

    return 0;
}
