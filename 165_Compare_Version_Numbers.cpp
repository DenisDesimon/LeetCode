//#165 Compare Version Numbers - https://leetcode.com/problems/compare-version-numbers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    vector<int> getNums(string &version){
        vector<int> result;
        string num = "";
        for(int i = 0; i < (int)version.size(); i++)
        {
            if(version[i] == '.')
            {
                result.push_back(stoi(num));
                num = "";
                continue;
            }
            num += version[i];
        }
        result.push_back(stoi(num));
        return result;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> left = getNums(version1);
        vector<int> right = getNums(version2);
        auto size = max(left.size(), right.size());
        while(left.size() != size)
            left.push_back(0);
        while(right.size() != size)
            right.push_back(0);
        for(int i = 0; i < (int)size; i++)
        {
            if(left[i] > right[i])
                return 1;
            if(left[i] < right[i])
                return -1;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    string givenVersion1 = "1.01";
    string givenVersion2 = "1.001";
    int expectedAnswer = 0;
    assert(solution.compareVersion(givenVersion1, givenVersion2) == expectedAnswer);

    givenVersion1 = "1.1";
    givenVersion2 = "1.2";
    expectedAnswer = -1;
    assert(solution.compareVersion(givenVersion1, givenVersion2) == expectedAnswer);

    return 0;
}
