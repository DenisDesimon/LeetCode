//#347 Top K Frequent Elements - https://leetcode.com/problems/top-k-frequent-elements/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<int> result;
        priority_queue<pair<int, int>> frequency;
        for(auto& num : nums)
            hash[num]++;
        for(auto& num : hash)
            frequency.push({num.second, num.first});
        while(k--)
        {
            result.push_back(frequency.top().second);
            frequency.pop();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 0, 1, 0};
    int given_k = 1;
    vector<int> expected_answer = {0};
    assert(solution.topKFrequent(given_nums, given_k) == expected_answer);

    given_nums = {1, 1, 1 ,2, 2, 3};
    given_k = 2;
    expected_answer = {1, 2};
    assert(solution.topKFrequent(given_nums, given_k) == expected_answer);

    return 0;
}
