//#1207 Unique Number of Occurrences - https://leetcode.com/problems/unique-number-of-occurrences/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurences;
        unordered_set<int> unique;
        for(auto& num : arr)
            occurences[num]++;
        for(auto& occur : occurences)
        {
            if(unique.count(occur.second))
                return false;
            unique.insert(occur.second);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {1, 2, 2, 1, 1, 3};
    bool expected_answer = true;
    assert(solution.uniqueOccurrences(given_arr) == expected_answer);

    given_arr = {1, 2};
    expected_answer = false;
    assert(solution.uniqueOccurrences(given_arr) == expected_answer);

    return 0;
}
