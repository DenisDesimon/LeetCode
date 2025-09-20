//#3508 Implement Router  - https://leetcode.com/problems/implement-router/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

class Router {
private:
    int memoryLimit;
    set<tuple<int, int, int>> sourceDestTime;
    queue<pair<int, pair<int, int>>> routeOrder;
    unordered_map<int, vector<int>> destTime;
    unordered_map<int, int> destStart;
public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if(sourceDestTime.count(make_tuple(source, destination, timestamp)))
            return false;
        if((int)routeOrder.size() == memoryLimit)
        {
            auto firstRoute = routeOrder.front();
            sourceDestTime.erase({firstRoute.first, firstRoute.second.first, firstRoute.second.second});
            destStart[firstRoute.second.first]++;
            routeOrder.pop();
        }
        routeOrder.push({source, {destination, timestamp}});
        sourceDestTime.insert({source, destination, timestamp});
        destTime[destination].push_back(timestamp);
        return true;
    }

    vector<int> forwardPacket() {
        if(routeOrder.empty())
            return {};
        auto firstRoute = routeOrder.front();
        sourceDestTime.erase({firstRoute.first, firstRoute.second.first, firstRoute.second.second});
        destStart[firstRoute.second.first]++;
        routeOrder.pop();
        return {firstRoute.first, firstRoute.second.first, firstRoute.second.second};
    }

    int getCount(int destination, int startTime, int endTime) {
        int start = destStart[destination];
        return int(upper_bound(destTime[destination].begin() + start, destTime[destination].end(), endTime) -
                   lower_bound(destTime[destination].begin() + start, destTime[destination].end(), startTime));
    }
};


int main()
{
    int givenMemoryLimit = 3;
    Router solution(givenMemoryLimit);

    int givenSource = 1;
    int givenDestination = 4;
    int givenTimestamp = 90;
    solution.addPacket(givenSource, givenDestination, givenTimestamp);

    givenSource = 2;
    givenDestination = 5;
    givenTimestamp = 90;
    solution.addPacket(givenSource, givenDestination, givenTimestamp);

    givenSource = 1;
    givenDestination = 4;
    givenTimestamp = 90;
    solution.addPacket(givenSource, givenDestination, givenTimestamp);

    givenSource = 3;
    givenDestination = 5;
    givenTimestamp = 95;
    solution.addPacket(givenSource, givenDestination, givenTimestamp);

    givenSource = 4;
    givenDestination = 5;
    givenTimestamp = 105;
    solution.addPacket(givenSource, givenDestination, givenTimestamp);

    vector<int> expectedAnswer = {2, 5, 90};
    assert(solution.forwardPacket() == expectedAnswer);

    int expectedCount = 1;
    givenSource = 5;
    int givenStartTime = 100;
    int givenEndTime = 110;
    assert(solution.getCount(givenSource, givenStartTime, givenEndTime) == expectedCount);

    return 0;
}
