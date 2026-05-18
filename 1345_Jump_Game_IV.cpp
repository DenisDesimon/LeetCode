//#1345 Jump Game IV - https://leetcode.com/problems/jump-game-iv/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> numIdxs;
        for(int i = 0; i < n; i++)
        {
            numIdxs[arr[i]].push_back(i);
        }
        queue<int> nodes;
        nodes.push(0);
        vector<int> visited(n);
        int result = 0;
        visited[0] = true;
        while(!nodes.empty())
        {
            int size = nodes.size();
            while(size--)
            {
                int cur = nodes.front();
                nodes.pop();
                if(cur == n - 1)
                    return result;
                if(cur - 1 >= 0 && !visited[cur - 1])
                {
                    nodes.push(cur - 1);
                    visited[cur - 1] = true;
                }
                if(cur + 1 < n && !visited[cur + 1])
                {
                    nodes.push(cur + 1);
                    visited[cur + 1] = true;
                }
                for(auto &next : numIdxs[arr[cur]])
                {
                    if(next == cur)
                        continue;
                    if(!visited[next])
                        nodes.push(next);
                    visited[next] = true;
                }
                numIdxs[arr[cur]].clear();
            }
            result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr  = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
    int expectedAnswer = 3;
    assert(solution.minJumps(givenArr) == expectedAnswer);

    givenArr  = {7, 6, 9, 6, 9, 6, 9, 7};
    expectedAnswer = 1;
    assert(solution.minJumps(givenArr) == expectedAnswer);

    return 0;
}
