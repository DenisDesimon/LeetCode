//#164 Maximum Gap - https://leetcode.com/problems/maximum-gap/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Bucket{
public:
    bool used = false;
    int minval = INT_MAX;
    int maxval = INT_MIN;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if((int)nums.size() < 2)
            return 0;
        int min_num = nums[0], max_num = nums[0];
        for(auto &num : nums)
        {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        int bucket_size = max(1, (max_num - min_num) / ((int)nums.size() - 1));
        int bucket_num = (max_num - min_num) / bucket_size + 1;
        vector<Bucket> buckets(bucket_num);
        for(auto &num : nums)
        {
            int idx = (num - min_num) / bucket_size;
            buckets[idx].used = true;
            buckets[idx].minval = min(num, buckets[idx].minval);
            buckets[idx].maxval = max(num, buckets[idx].maxval);
        }
        int prev = min_num, result = 0;
        for(auto &bucket : buckets)
        {
            if(!bucket.used)
                continue;
            result = max(result, bucket.minval - prev);
            prev = bucket.maxval;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 6, 9, 1};
    int expected_answer = 3;
    assert(solution.maximumGap(given_nums) == expected_answer);

    given_nums = {10};
    expected_answer = 0;
    assert(solution.maximumGap(given_nums) == expected_answer);

    return 0;
}
