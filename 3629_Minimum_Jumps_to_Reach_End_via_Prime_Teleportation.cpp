//#3629 Minimum Jumps to Reach End via Prime Teleportation - https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

const int factSize = 1000001;
vector<int> fact[factSize];

bool initialize = [](){
    for(int i = 2; i < factSize; i++)
    {
        if(fact[i].empty())
        {
            for(int j = i; j < factSize; j += i)
                fact[j].push_back(i);
        }
    }
    return true;
}();



class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int, vector<int>> edges;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int &p : fact[nums[i]])
                edges[p].push_back(i);
        }
        queue<int> pq;
        pq.push(0);
        int path = 0;
        vector<bool> visited(n);
        visited[0] = true;
        while(!pq.empty())
        {
            int size = pq.size();
            while(size)
            {
                int cur = pq.front();
                pq.pop();
                if(cur == n - 1)
                    return path;
                if(cur > 0 && !visited[cur - 1])
                {
                    pq.push(cur - 1);
                    visited[cur - 1] = true;
                }
                if(!visited[cur + 1])
                {
                    pq.push(cur + 1);
                    visited[cur + 1] = true;
                }
                if((int)fact[nums[cur]].size() == 1)
                {
                    if(edges.count(nums[cur]))
                    {
                        for(auto &next : edges[nums[cur]])
                        {
                            if(!visited[next])
                            {
                                pq.push(next);
                                visited[next] = true;
                            }
                        }
                    }
                    edges[nums[cur]].clear();
                }
                size--;
            }
            path++;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 4, 6};
    int expectedAnswer = 2;
    assert(solution.minJumps(givenNums) == expectedAnswer);

    givenNums = {2, 3, 4, 7, 9};
    expectedAnswer = 2;
    assert(solution.minJumps(givenNums) == expectedAnswer);

    return 0;
}
