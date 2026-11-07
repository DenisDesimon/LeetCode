//#1882 Process Tasks Using Servers - https://leetcode.com/problems/process-tasks-using-servers/
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
using namespace std;

class Solution {
 public:
     vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nextServer;
         priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyServers;
         int n = servers.size();
         int m = tasks.size();
         for(int i = 0; i < n; i++)
             nextServer.push({servers[i], i});
         vector<int> result;
         long long time = 0;
         auto releaseServers = [&](){
             while(!busyServers.empty() && busyServers.top().first <= time)
             {
                 nextServer.push({servers[busyServers.top().second], busyServers.top().second});
                 busyServers.pop();
             }
         };
         for(int i = 0; i < m; i++)
         {
             time = max(time, (long long)i);
             releaseServers();
             if(nextServer.empty())
             {
                 time = busyServers.top().first;
                 releaseServers();
             }
             busyServers.push({time + tasks[i], nextServer.top().second});
             result.push_back(nextServer.top().second);
             nextServer.pop();
         }
         return result;
     }
 };

int main()
{
    Solution solution;
    vector<int> givenServers = {3, 3, 2};
    vector<int> givenTasks = {1, 2, 3, 2, 1, 2};
    vector<int> expectedAnswer = {2, 2, 0, 2, 1, 2};
    assert(solution.assignTasks(givenServers, givenTasks) == expectedAnswer);

    givenServers = {5, 1, 4, 3, 2};
    givenTasks = {2, 1, 2, 4, 5, 2, 1};
    expectedAnswer = {1, 4, 1, 4, 1, 3, 2};
    assert(solution.assignTasks(givenServers, givenTasks) == expectedAnswer);

    return 0;
}
