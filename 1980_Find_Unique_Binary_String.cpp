//#1980 Find Unique Binary String - https://leetcode.com/problems/find-unique-binary-string/
#include <iostream>
#include <cassert>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> uniqueNums;
        for(auto &num : nums)
        {
            uniqueNums.insert(stoi(num, 0, 2));
        }
        for(int i = 0; i < n + 1; i++)
        {
            if(!uniqueNums.count(i))
            {
                string result = "";
                for(int j = n - 1; j >= 0; j--)
                {
                    if(i & (1 << j))
                        result += '1';
                    else
                        result += '0';
                }
                return result;
            }
        }
        return "";
    }
};

int main()
{
    Solution solution;
    vector<string> givenS = {"111", "011", "001"};
    string expectedAnswer = "000";
    assert(solution.findDifferentBinaryString(givenS) == expectedAnswer);

    givenS = {"00", "01"};
    expectedAnswer = "10";
    assert(solution.findDifferentBinaryString(givenS) == expectedAnswer);

    return 0;
}
