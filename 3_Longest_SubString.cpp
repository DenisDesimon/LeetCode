//#3 Longest Substring Without Repeating Characters - https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     unordered_map<char,int> HashMap;
     int answer = 0;
     for(int i = 0, j = 0; i < (int)s.size(); i++){
        if(HashMap.count(s[i]))
          j = max(HashMap[s[i]], j);
        answer = max(answer, i - j + 1);
        HashMap[s[i]] = i + 1;
                                                  }
     return answer;
                                            }
};

int main()
{
    Solution solution;
    string given_string = "abcabcbb";
    int expected_answer = 3;
    assert(solution.lengthOfLongestSubstring(given_string) == expected_answer);

    given_string = "bbbbb";
    expected_answer = 1;
    assert(solution.lengthOfLongestSubstring(given_string) == expected_answer);


        return 0;
    }
