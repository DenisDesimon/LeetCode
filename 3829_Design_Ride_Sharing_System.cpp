//#3829 Design Ride Sharing System - https://leetcode.com/problems/design-ride-sharing-system/
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

class RideSharingSystem {
private:
    queue<int> riders;
    queue<int> drivers;
    bool isAvailable[1001] = {false};
public:
    RideSharingSystem() {

    }

    void addRider(int riderId) {
        riders.push(riderId);
        isAvailable[riderId] = true;
    }

    void addDriver(int driverId) {
        drivers.push(driverId);
    }

    vector<int> matchDriverWithRider() {
        while(!riders.empty() && !drivers.empty())
        {
            int rider = riders.front();
            riders.pop();
            if(!isAvailable[rider])
                continue;
            isAvailable[rider] = false;
            int driver = drivers.front();
            drivers.pop();
            return {driver, rider};
        }
        return {-1, -1};
    }

    void cancelRider(int riderId) {
        if(isAvailable[riderId])
            isAvailable[riderId] = false;
    }
};

int main()
{
    RideSharingSystem cowboys;
    cowboys.addRider(3);
    cowboys.addDriver(2);
    cowboys.addRider(1);
    vector<int> expectedAnswer = {2, 3};
    assert(cowboys.matchDriverWithRider() == expectedAnswer);

    cowboys.addDriver(5);
    cowboys.cancelRider(3);
    expectedAnswer = {5, 1};
    assert(cowboys.matchDriverWithRider() == expectedAnswer);

    expectedAnswer = {-1, -1};
    assert(cowboys.matchDriverWithRider() == expectedAnswer);


    return 0;
}
