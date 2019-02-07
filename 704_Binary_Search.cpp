//#704 Binary Search - https://leetcode.com/problems/binary-search/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int k = 0, n=(int)nums.size();
       for(int b = n/2; b>=1; b/=2)
       {
           while(k + b < n && target >= nums[k+b]) k+=b;

       }
         if(target == nums[k])
               return k;
       return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {-1, 0, 3, 5, 9, 12};
    int expected_target = 9;
    int expected_answer = 4;
    assert(solution.search(given_nums, expected_target) == expected_answer);

    expected_target = 2;
    expected_answer = -1;
    assert(solution.search(given_nums, expected_target) == expected_answer);


        return 0;
    }

