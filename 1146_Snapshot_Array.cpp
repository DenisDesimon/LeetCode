//#1146 Snapshot Array - https://leetcode.com/problems/snapshot-array/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class SnapshotArray {
    vector<int> array;
    vector<vector<pair<int, int>>> snap_shots;
    int snap_id = 0;
public:
    SnapshotArray(int length) {
        snap_shots.push_back({});
        for(int i = 0; i < length; i++)
            snap_shots[0].push_back({i, 0});
        array.resize(length, 0);
    }

    void set(int index, int val) {
        array[index] = val;
        snap_shots[snap_id].push_back({index, val});
    }

    int snap() {
        snap_shots.push_back({});
        return snap_id++;
    }

    int get(int index, int snap_id) {
        for(int i = snap_id; i >= 0; i--)
        {
            for(int j = snap_shots[i].size() - 1; j >= 0; j--)
            {
                if(snap_shots[i][j].first == index)
                    return snap_shots[i][j].second;
            }
        }
        return array[index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main()
{
    SnapshotArray solution(6);
    solution.snap();
    solution.set(1, 8);
    int expected_answer = 0;
    assert(solution.get(1, 0) == expected_answer);

    solution.set(2, 4);
    solution.set(3, 5);
    solution.snap();
    expected_answer = 5;
    assert(solution.get(3, 1) == expected_answer);

    return 0;
}
