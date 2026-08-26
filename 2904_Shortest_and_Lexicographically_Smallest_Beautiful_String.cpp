//#2904 Shortest and Lexicographically Smallest Beautiful String - https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int right = 0, left = 0, count = 0;
        string result = s + 'a';
        for(; right < (int)s.size(); right++)
        {
            count += s[right] - '0';
            while(count > k || s[left] == '0')
            {
                count -= s[left] - '0';
                left++;
            }
            if(count == k)
            {
                string cur = s.substr(left, right - left + 1);
                if(cur.size() < result.size())
                    result = cur;
                else if(cur.size() == result.size())
                    result = min(result, cur);
            }
        }
        return result == s + 'a' ? "" : result;
    }
};

int main()
{
    Solution solution;
    string givenS = "100011001";
    int givenK = 3;
    string expectedAnswer = "11001";
    assert(solution.shortestBeautifulSubstring(givenS, givenK) == expectedAnswer);

    givenS = "1011";
    givenK = 2;
    expectedAnswer = "11";
    assert(solution.shortestBeautifulSubstring(givenS, givenK) == expectedAnswer);


    return 0;
}
