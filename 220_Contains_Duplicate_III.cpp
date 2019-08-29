//#220 Contains Duplicate III - https://leetcode.com/problems/contains-duplicate-iii/
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multimap<long long, long long> hashmap;
        for(int i = 0; i < (int)nums.size(); i++)
        {
                auto lower = hashmap.lower_bound((long long)nums[i] - (long long)t);
                while(lower != hashmap.end() && abs(nums[i] - lower->first) <= t)
                {
                    if(i - lower->second <= k)
                        return true;
                    lower++;
                }
                hashmap.insert({nums[i], i});
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 1};
    int given_k = 3;
    int given_t = 0;
    bool expected_answer = true;
    assert(solution.containsNearbyAlmostDuplicate(given_nums, given_k, given_t) == expected_answer);

    given_nums = {1, 0, 1, 1};
    given_k = 1;
    given_t = 2;
    expected_answer = true;
    assert(solution.containsNearbyAlmostDuplicate(given_nums, given_k, given_t) == expected_answer);

    return 0;
}
