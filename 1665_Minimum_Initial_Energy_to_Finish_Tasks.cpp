//#1665 Minimum Initial Energy to Finish Tasks - https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int> &left, vector<int> &right){
            return left[1] - left[0] < right[1] - right[0];
        });
        int result = 0;
        for(auto &task : tasks)
            result = max(result + task[0], task[1]);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenTasks  = {{1, 2}, {2, 4}, {4, 8}};
    int expectedAnswer = 8;
    assert(solution.minimumEffort(givenTasks) == expectedAnswer);

    givenTasks = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};
    expectedAnswer = 32;
    assert(solution.minimumEffort(givenTasks) == expectedAnswer);

    return 0;
}
