//#1340 Jump Game V - https://leetcode.com/problems/jump-game-v/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
private:
    int dfs(int cur, int d, vector<int> &arr, vector<int> &path){
        if(path[cur] != -1)
            return path[cur];
        int n = arr.size();
        int result = 1;
        for(int left = cur - 1; left >= 0 && cur - left <= d; left--)
        {
            if(arr[left] >= arr[cur])
                break;
            result = max(result, dfs(left, d, arr, path) + 1);
        }
        for(int right = cur + 1; right < n && right - cur <= d; right++)
        {
            if(arr[right] >= arr[cur])
                break;
            result = max(result, dfs(right, d, arr, path) + 1);
        }
        return path[cur] = result;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int result = 0;
        vector<int> path(n, -1);
        for(int i = 0; i < n; i++)
            result = max(result, dfs(i, d, arr, path));
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr  = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
    int givenD = 2;
    int expectedAnswer = 4;
    assert(solution.maxJumps(givenArr, givenD) == expectedAnswer);

    givenArr  = {3, 3, 3, 3, 3};
    givenD = 3;
    expectedAnswer = 1;
    assert(solution.maxJumps(givenArr, givenD) == expectedAnswer);

    return 0;
}
