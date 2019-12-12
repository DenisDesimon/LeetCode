//#1282 Group the People Given the Group Size They Belong To - https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> hash;
        for(int i = 0; i < (int)groupSizes.size(); i++)
            hash[groupSizes[i]].push_back(i);
        for(auto pair : hash)
        {
            int size = groupSizes[pair.second[0]];
            for(auto start = pair.second.begin(); start != pair.second.end(); start += size)
                result.push_back(vector<int>(start, start + size));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_groups = {3, 3, 3, 3, 3, 1, 3};
    vector<vector<int>> expected_answer = {{5}, {0, 1, 2}, {3, 4, 6}};
    assert(solution.groupThePeople(given_groups) == expected_answer);

    given_groups = {2, 1, 3, 3, 3, 2};
    expected_answer = {{2, 3, 4}, {0, 5}, {1}};
    auto res = solution.groupThePeople(given_groups);
    assert(solution.groupThePeople(given_groups) == expected_answer);

    return 0;
}
