//#2211 Count Collisions on a Road - https://leetcode.com/problems/count-collisions-on-a-road/
#include <iostream>
#include <cassert>

using namespace std;


class Solution {
public:
    int countCollisions(string directions) {
        int prev = -1, result = 0;
        for(int i = 0; i < (int)directions.size(); i++)
        {
            switch(directions[i]){
                case 'L':
                    if(prev >= 0)
                    {
                        result += prev + 1;
                        prev = 0;
                    }
                    break;
                case 'R':
                    if(prev > 0)
                        prev++;
                    else
                        prev = 1;
                    break;
                case 'S':
                    if(prev > 0)
                        result += prev;
                    prev = 0;
                    break;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenDirections = "RLRSLL";
    int expectedAnswer = 5;
    assert(solution.countCollisions(givenDirections) == expectedAnswer);

    givenDirections = "LLRR";
    expectedAnswer = 0;
    assert(solution.countCollisions(givenDirections) == expectedAnswer);

    return 0;
}
