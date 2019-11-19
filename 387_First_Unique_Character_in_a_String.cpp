//#387 First Unique Character in a String - https://leetcode.com/problems/first-unique-character-in-a-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int alphabet[26] = {0};
        for(int i = 0; i < (int)s.size(); i++)
        {
            alphabet[s[i] - 'a']++;
        }
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(alphabet[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    string given_s = "leetcode";
    int expected_answer = 0;
    assert(solution.firstUniqChar(given_s) == expected_answer);

    given_s = "loveleetcode";
    expected_answer = 2;
    assert(solution.firstUniqChar(given_s) == expected_answer);

    return 0;
}
