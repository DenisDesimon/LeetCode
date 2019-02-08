//#349 Intersection of Two Arrays - https://leetcode.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <cassert>


using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
unordered_set<int> HashSet(nums1.begin(), nums1.end());
vector<int> result;

            for(int i = 0; i < (int)nums2.size(); i++)
            {
                if(HashSet.count(nums2[i])){
                    result.push_back(nums2[i]);
                    HashSet.erase(nums2[i]);
                                           }
            }
return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums1 = {1, 2, 2, 1}, given_nums2 = {2, 2};
    vector<int> expected_answer = {2};
    assert(solution.intersection(given_nums1, given_nums2) == expected_answer);

    given_nums1 = {4, 9, 5}, given_nums2 = {9, 4, 9, 8, 4};
    expected_answer = {9, 4};
    assert(solution.intersection(given_nums1, given_nums2) == expected_answer);

    return 0;
}
