//#630 Course Schedule III - https://leetcode.com/problems/course-schedule-iii/
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int> &op1, const vector<int> &op2) { return op1[1] < op2[1]; });
        priority_queue<int> max_heap;
        int timestamp = 0;
        for(int i = 0; i < (int)courses.size(); i++)
        {
            max_heap.push(courses[i][0]);
            timestamp += courses[i][0];
            if(timestamp > courses[i][1])
                {
                timestamp -= max_heap.top();
                max_heap.pop();
                }
        }
        return max_heap.size();
    }
};
int main()
{
    Solution solution;
    vector<vector<int>> given_nums = {{5,15},{3,19},{6,7},{2,10},{5,16},{8,14},{10,11},{2,19}};
    int expected_answer = 5;
    assert(solution.scheduleCourse(given_nums) == expected_answer);

    given_nums = {{5,5},{4,7},{2,6}};
    expected_answer = 2;
    assert(solution.scheduleCourse(given_nums) == expected_answer);

    return 0;
}
