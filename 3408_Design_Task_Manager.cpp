//#3408 Design Task Manager  - https://leetcode.com/problems/design-task-manager/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>
using namespace std;

class TaskManager {
private:
    set<pair<int, int>> priorityTask;
    unordered_map<int, int> taskPriority;
    unordered_map<int, int> taskUser;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks)
        {
            priorityTask.insert({task[2], task[1]});
            taskPriority[task[1]] = task[2];
            taskUser[task[1]] = task[0];
        }
    }

    void add(int userId, int taskId, int priority) {
        priorityTask.insert({priority, taskId});
        taskPriority[taskId] = priority;
        taskUser[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        priorityTask.erase({taskPriority[taskId], taskId});
        taskPriority[taskId] = newPriority;
        priorityTask.insert({newPriority, taskId});
    }

    void rmv(int taskId) {
        priorityTask.erase({taskPriority[taskId], taskId});
        taskPriority.erase(taskId);
        taskUser.erase(taskId);
    }

    int execTop() {
        if(priorityTask.empty())
            return -1;
        auto iter = --priorityTask.end();
        int result = taskUser[(iter->second)];
        taskPriority.erase(iter->second);
        taskUser.erase(iter->second);
        priorityTask.erase(iter);
        return result;
    }
};

int main()
{
    vector<vector<int>> givenTasks  = {{1, 101, 10}, {2, 102, 20}, {3, 103, 15}};
    int givenUserId = 4;
    int givenTaskId = 104;
    int givenPriority = 14;
    int givenNewPriority = 8;
    int expectedAnswer = 2;
    TaskManager solution(givenTasks);
    assert(solution.execTop() == expectedAnswer);

    solution.add(givenUserId, givenTaskId, givenPriority);
    givenTaskId = 102;
    solution.edit(givenTaskId, givenNewPriority);
    givenTaskId = 103;
    solution.rmv(givenTaskId);
    expectedAnswer = 4;
    assert(solution.execTop() == expectedAnswer);

    return 0;
}
