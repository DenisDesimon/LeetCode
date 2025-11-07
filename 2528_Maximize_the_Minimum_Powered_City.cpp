//#2528 Maximize the Minimum Powered City - https://leetcode.com/problems/maximize-the-minimum-powered-city/
#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> difference(n + 1);
        for(int i = 0; i < n; i++)
        {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            difference[left] += stations[i];
            difference[right] -= stations[i];
        }
        auto isValidMinPower = [&](long long val) -> bool{
          vector<long long> updatedDif = difference;
          long long kLeft = k;
          long long curPower = 0;
          for(int i = 0; i < n; i++)
          {
              curPower += updatedDif[i];
              if(curPower < val)
              {
                  kLeft -= val - curPower;
                  if(kLeft < 0)
                      return false;
                  int right = min(n, i + 2 * r + 1);
                  updatedDif[right] -= val - curPower;
                  curPower += val - curPower;
              }
          }
          return true;
        };
        long long left = INT_MAX;
        for(auto &station : stations)
            left = min(left, (long long)station);
        long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long result = 0;
        while(left <= right)
        {
            long long mid = left + (right - left) / 2;
            if(isValidMinPower(mid))
            {
                result = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenStations = {1, 2, 4, 5, 0};
    int givenR = 1;
    int givenK = 2;
    int expectedAnswer = 5;
    assert(solution.maxPower(givenStations, givenR, givenK) == expectedAnswer);

    givenStations = {4, 4, 4, 4};
    givenR = 0;
    givenK = 3;
    expectedAnswer = 4;
    assert(solution.maxPower(givenStations, givenR, givenK) == expectedAnswer);

    return 0;
}
