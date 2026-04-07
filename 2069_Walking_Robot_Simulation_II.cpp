//#2069 Walking Robot Simulation II - https://leetcode.com/problems/walking-robot-simulation-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Robot {
private:
    int circleLength, curCircle;
    vector<pair<string, pair<int, int>>> circleToPoint;
    bool isMoved = false;
public:
    Robot(int width, int height) {
        curCircle = 0;
        for(int i = 0; i < width; i++)
            circleToPoint.push_back({"East", {i, 0}});
        for(int i = 1; i < height; i++)
            circleToPoint.push_back({"North", {width - 1, i}});
        for(int i = width - 2; i >= 0; i--)
            circleToPoint.push_back({"West", {i, height - 1}});
        for(int i = height - 2; i >= 1; i--)
            circleToPoint.push_back({"South", {0, i}});
        circleLength = circleToPoint.size();
        circleToPoint[0].first = "South";
    }

    void step(int num) {
        isMoved = true;
        curCircle = (curCircle + num) % circleLength;
    }

    vector<int> getPos() {
        return {circleToPoint[curCircle].second.first, circleToPoint[curCircle].second.second};
    }

    string getDir() {
        if(!isMoved)
            return "East";
        return circleToPoint[curCircle].first;
    }
};

int main()
{
    int givenWidth = 6;
    int givenHeight = 3;
    Robot robot(givenWidth, givenHeight);
    int givenNum = 2;
    robot.step(givenNum);
    robot.step(givenNum);
    vector<int> expectedPos = {4, 0};

    string expectedDir = "East";
    assert(robot.getPos() == expectedPos);
    assert(robot.getDir() == expectedDir);

    robot.step(givenNum);
    givenNum = 1;
    robot.step(givenNum);
    givenNum = 4;
    robot.step(givenNum);

    expectedPos = {1, 2};
    expectedDir = "West";
    assert(robot.getPos() == expectedPos);
    assert(robot.getDir() == expectedDir);

    return 0;
}
