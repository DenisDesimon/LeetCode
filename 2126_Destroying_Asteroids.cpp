//#2126 Destroying Asteroids - https://leetcode.com/problems/destroying-asteroids/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long total = mass;
        for(auto &asteroid : asteroids)
        {
            if(asteroid > total)
                return false;
            total += asteroid;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    int givenMass = 10;
    vector<int> givenAsteroids = {3, 9, 19, 5, 21};
    bool expectedAnswer = true;
    assert(solution.asteroidsDestroyed(givenMass, givenAsteroids) == expectedAnswer);

    givenMass = 5;
    givenAsteroids = {4, 9, 23, 4};
    expectedAnswer = false;
    assert(solution.asteroidsDestroyed(givenMass, givenAsteroids) == expectedAnswer);

    return 0;
}
