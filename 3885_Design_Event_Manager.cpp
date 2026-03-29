//#3885 Design Event Manager - https://leetcode.com/problems/design-event-manager/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
};

class EventManager {
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    unordered_map<int, int> idPriority;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto &event : events)
        {
            idPriority[event[0]] = event[1];
            pq.push({event[1], event[0]});
        }
    }

    void updatePriority(int eventId, int newPriority) {
        idPriority[eventId] = newPriority;
        pq.push({newPriority, eventId});
    }

    int pollHighest() {
        while(!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            if(idPriority[top.second] == top.first)
            {
                idPriority.erase(top.second);
                return top.second;
            }
        }
        return -1;
    }
};

int main()
{
    vector<vector<int>> givenEvents = {{5, 7}, {2, 7}, {9, 4}};
    EventManager solution(givenEvents);
    int expectedAnswer = 2;
    assert(solution.pollHighest() == expectedAnswer);

    int givenId = 9;
    int givenPriority = 7;
    solution.updatePriority(givenId, givenPriority);

    expectedAnswer = 5;
    assert(solution.pollHighest() == expectedAnswer);

    expectedAnswer = 9;
    assert(solution.pollHighest() == expectedAnswer);


    return 0;
}
