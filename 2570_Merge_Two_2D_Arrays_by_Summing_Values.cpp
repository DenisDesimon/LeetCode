//#2570 Merge Two 2D Arrays by Summing Values - https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
      int pointer1 = 0, pointer2 = 0;
      vector<vector<int>> result;
      while(pointer1 < (int)nums1.size() && pointer2 < (int)nums2.size())
      {
          if(nums1[pointer1][0] == nums2[pointer2][0])
          {
              result.push_back({nums1[pointer1][0], nums1[pointer1][1] + nums2[pointer2][1]});
              pointer1++, pointer2++;
          }
          else if(nums1[pointer1][0] > nums2[pointer2][0])
          {
              result.push_back(nums2[pointer2]);
              pointer2++;
          }
          else
          {
              result.push_back(nums1[pointer1]);
              pointer1++;
          }
      }
      while(pointer1 < (int)nums1.size())
      {
          result.push_back(nums1[pointer1]);
          pointer1++;
      }
      while(pointer2 < (int)nums2.size())
      {
          result.push_back(nums2[pointer2]);
          pointer2++;
      }
      return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> given_nums2 = {{1, 4}, {3, 2}, {4, 1}};
    vector<vector<int>> expected_answer = {{1, 6}, {2, 3}, {3, 2}, {4, 6}};
    assert(solution.mergeArrays(given_nums1, given_nums2) == expected_answer);

    given_nums1 = {{2, 4}, {3, 6}, {5, 5}};
    given_nums2 = {{1,3}, {4, 3}};
    expected_answer = {{1, 3}, {2, 4}, {3, 6}, {4, 3}, {5, 5}};
    assert(solution.mergeArrays(given_nums1, given_nums2) == expected_answer);

    return 0;
}
