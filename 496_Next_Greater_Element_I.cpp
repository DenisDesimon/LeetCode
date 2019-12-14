//#496 Next Greater Element I - https://leetcode.com/problems/next-greater-element-i/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> prev;
        unordered_map<int, int> hash;
        vector<int> result;
        for(auto& num : nums2)
        {
            while(!prev.empty() && prev.top() < num)
            {
                hash[prev.top()] = num;
                prev.pop();
            }
            prev.push(num);
        }
        for(auto& num : nums1)
        {
            if(hash.count(num))
                result.push_back(hash[num]);
            else result.push_back(-1);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_num1 = {4, 1, 2};
    vector<int> given_num2 = {1, 3, 4, 2};
    vector<int> expected_answer = {-1, 3, -1};
    assert(solution.nextGreaterElement(given_num1, given_num2) == expected_answer);

    given_num1 = {2, 4};
    given_num2 = {1, 2, 3, 4};
    expected_answer = {3, -1};
    assert(solution.nextGreaterElement(given_num1, given_num2) == expected_answer);

    return 0;
}
