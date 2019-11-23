//#447 Number of Boomerangs - https://leetcode.com/problems/number-of-boomerangs/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
    int dist(vector<int> p1, vector<int> p2){
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int result = 0;
        unordered_map<int, int> hash;
        for(auto& p1 : points)
        {
            hash.clear();
            for(auto& p2 : points)
            {
                if(p1 == p2)
                    continue;
                hash[dist(p1, p2)]++;
            }
            for(auto& count : hash)
            {
                if(count.second < 2)
                    continue;
                result += count.second * (count.second - 1);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_points = {{0, 0}, {1, 0}, {2, 0}};
    int expected_answer = 2;
    assert(solution.numberOfBoomerangs(given_points) == expected_answer);

    return 0;
}
