//#1306 Jump Game III - https://leetcode.com/problems/jump-game-iii/
#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n);
        stack<int> nodes;
        nodes.push(start);
        while(!nodes.empty())
        {
            int cur = nodes.top();
            nodes.pop();
            if(visited[cur])
                continue;
            visited[cur] = true;
            if(arr[cur] == 0)
                return true;
            if(arr[cur] + cur < n && !visited[arr[cur] + cur])
                nodes.push(arr[cur] + cur);
            if(cur - arr[cur] >= 0 && !visited[cur - arr[cur]])
                nodes.push(cur - arr[cur]);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr  = {4, 2, 3, 0, 3, 1, 2};
    int givenStart = 5;
    bool expectedAnswer = true;
    assert(solution.canReach(givenArr, givenStart) == expectedAnswer);

    givenArr  = {3, 0, 2, 1, 2};
    givenStart  = 2;
    expectedAnswer = false;
    assert(solution.canReach(givenArr, givenStart) == expectedAnswer);

    return 0;
}
