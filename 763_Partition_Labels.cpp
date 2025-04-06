//#763 Partition Labels - https://leetcode.com/problems/partition-labels/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution{
public:
    vector<int> partitionLabels(string s){
        unordered_map<char, int> lastPosition;
        vector<int> result;
        for(int i = 0; i < (int)s.size(); i++)
        {
            lastPosition[s[i]] = i;
        }
        int maxLastPos = -1;
        int left = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            maxLastPos = max(maxLastPos, lastPosition[s[i]]);
            if(i == maxLastPos)
            {
                result.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "ababcbacadefegdehijhklij";
    vector<int> expectedAnswer = {9, 7, 8};
    assert(solution.partitionLabels(givenS) == expectedAnswer);

    givenS = "eccbbbbdec";
    expectedAnswer = {10};
    assert(solution.partitionLabels(givenS) == expectedAnswer);


    return 0;
}
