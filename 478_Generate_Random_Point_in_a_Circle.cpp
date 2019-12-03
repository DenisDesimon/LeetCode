//#478 Generate Random Point in a Circle - https://leetcode.com/problems/generate-random-point-in-a-circle/
#include <iostream>
#include <vector>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
    double radius, x_center, y_center;
 public:
     Solution(double radius, double x_center, double y_center) {
         this->radius = radius;
         this->x_center = x_center;
         this->y_center = y_center;
     }

     vector<double> randPoint(){
         while(true)
         {
             double x = 2 * radius * (double)(rand() / (double)RAND_MAX) + x_center - radius;
             double y = 2 * radius * (double)(rand() / (double)RAND_MAX) + y_center - radius;
             if(pow(x - x_center, 2) + pow(y - y_center, 2) <= radius * radius)
                 return {x, y};
         }
     }
 };

 /**
  * Your Solution object will be instantiated and called as such:
  * Solution* obj = new Solution(radius, x_center, y_center);
  * vector<double> param_1 = obj->randPoint();
  */

int main()
{
    double given_radius = 1;
    double given_x = 0;
    double given_y = 0;
    Solution solution(given_radius, given_x, given_y);
    vector<double> result = solution.randPoint();
    assert(result[0] >= (given_x - given_radius) && result[0] <= (given_x + given_radius) && result[1] >= (given_y - given_radius) && result[1] <= (given_y + given_radius) && pow(result[0] - given_x, 2) + pow(result[1] - given_y, 2) <= given_radius * given_radius);

    return 0;
}
