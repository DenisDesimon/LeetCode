//#3614 Process String with Special Operations II - https://leetcode.com/problems/process-string-with-special-operations-ii/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
       long long len = 0;
       for(auto &letter : s)
       {
           if(letter == '*')
               len = len ? len - 1 : len;
           else if(letter == '#')
               len *= 2;
           else if(letter == '%')
               continue;
           else
               len++;
       }
       if(k >= len)
           return '.';
       for(int i = s.size() - 1; i >= 0; i--)
       {
           if(s[i] == '*')
               len++;
           else if(s[i] == '#')
           {
               if(k >= len / 2)
                   k -= len / 2;
               len /= 2;
           }
           else if(s[i] == '%')
               k = len - 1 - k;
           else
           {
               if(k == len - 1)
                   return s[i];
               else
                   len--;
           }
       }
       return '.';
    }
};

int main()
{
    Solution solution;
    string givenS = "a#b%*";
    int givenK = 1;
    char expectedAnswer = 'a';
    assert(solution.processStr(givenS, givenK) == expectedAnswer);

    givenS = "cd%#*#";
    givenK = 3;
    expectedAnswer = 'd';
    assert(solution.processStr(givenS, givenK) == expectedAnswer);

    return 0;
}
