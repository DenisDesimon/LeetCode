//#3467 Transform Array by Parity - https://leetcode.com/problems/transform-array-by-parity/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution{
public:
    vector<int> transformArray(vector<int>& nums){
        vector<int> result;
        for(auto& num : nums){
            if(num % 2 == 1)
                result.push_back(1);
            else
                result.insert(result.begin(), 0);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {4, 3, 2, 1};
    vector<int> expected_answer = {0, 0, 1, 1};
    assert(solution.transformArray(given_nums) == expected_answer);

    given_nums = {1, 5, 1, 4, 2};
    expected_answer = {0, 0, 1, 1, 1};
    assert(solution.transformArray(given_nums) == expected_answer);

    return 0;
}
