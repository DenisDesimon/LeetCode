//#841 Keys and Rooms - https://leetcode.com/problems/keys-and-rooms/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int num_rooms = (int)rooms.size();
        vector<bool> visited(num_rooms, false);
        queue<int> nodes;
        nodes.push(0);
        while(!nodes.empty())
        {
            int cur_room = nodes.front();
            nodes.pop();
            if(visited[cur_room])
                continue;
            visited[cur_room] = true;
            num_rooms--;
            for(auto &room : rooms[cur_room])
            {
                nodes.push(room);
            }
        }
        return num_rooms == 0;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_rooms = {{1}, {2}, {3}, {}};
    bool expected_answer = true;
    assert(solution.canVisitAllRooms(given_rooms) == expected_answer);

    given_rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    expected_answer = false;
    assert(solution.canVisitAllRooms(given_rooms) == expected_answer);

    return 0;
}
