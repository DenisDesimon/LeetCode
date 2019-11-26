//#406 Queue Reconstruction by Height - https://leetcode.com/problems/queue-reconstruction-by-height/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];});
        vector<vector<int>> result;
        for(auto& person : people)
        {
            if(person[1] >= (int)result.size())
                result.push_back(person);
            else
                result.insert(result.begin() + person[1], person);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> expected_answer = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};
    assert(solution.reconstructQueue(given_people) == expected_answer);

    return 0;
}
